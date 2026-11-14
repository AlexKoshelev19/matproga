#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include "libxl.h"

using namespace std;
using namespace libxl;

const double EPS = 1e-9;

struct Constraint
{
    vector<double> a;
    string sign;
    double b;
};

struct LPProblem
{
    int n = 0;
    int m = 0;
    bool maximize = true;
    vector<double> objective;
    vector<Constraint> constraints;
};

struct ExcelContext
{
    Book* book = nullptr;
    Sheet* sheet = nullptr;
    int row = 0;

    Format* titleFmt = nullptr;
    Format* headerFmt = nullptr;
    Format* numFmt = nullptr;
    Format* pivotRowColFmt = nullptr;
    Format* pivotElemFmt = nullptr;
    Format* statusFmt = nullptr;
};

vector<vector<double>> matrix;
vector<int> basis;
vector<int> artificials;

int n_original = 0;
int n_total = 0;

// =====================================================
// ИНИЦИАЛИЗАЦИЯ EXCEL И СТИЛЕЙ
// =====================================================

bool init_excel(ExcelContext& xl)
{
    xl.book = xlCreateXMLBook();
    if (!xl.book)
    {
        cout << "Ошибка инициализации LibXL\n";
        return false;
    }

    // При наличии лицензионного ключа раскомментируйте строку ниже:
    // xl.book->setKey(L"Имя", L"Ключ");

    xl.sheet = xl.book->addSheet(L"Симплекс-метод");
    if (!xl.sheet)
    {
        xl.book->release();
        xl.book = nullptr;
        return false;
    }

    Font* boldFont = xl.book->addFont();
    boldFont->setBold(true);

    Font* titleFont = xl.book->addFont();
    titleFont->setBold(true);
    titleFont->setSize(12);

    xl.titleFmt = xl.book->addFormat();
    xl.titleFmt->setFont(titleFont);

    xl.statusFmt = xl.book->addFormat();
    xl.statusFmt->setFont(boldFont);

    xl.headerFmt = xl.book->addFormat();
    xl.headerFmt->setFont(boldFont);
    xl.headerFmt->setAlignH(ALIGNH_CENTER);
    xl.headerFmt->setBorder(BORDERSTYLE_THIN);
    xl.headerFmt->setFillPattern(FILLPATTERN_SOLID);
    xl.headerFmt->setPatternForegroundColor(COLOR_GRAY25);

    int customNumFmt = xl.book->addCustomNumFormat(L"0.000");

    xl.numFmt = xl.book->addFormat();
    xl.numFmt->setNumFormat(customNumFmt);
    xl.numFmt->setBorder(BORDERSTYLE_THIN);

    // Подсветка разрешающих строки и столбца
    xl.pivotRowColFmt = xl.book->addFormat();
    xl.pivotRowColFmt->setNumFormat(customNumFmt);
    xl.pivotRowColFmt->setBorder(BORDERSTYLE_THIN);
    xl.pivotRowColFmt->setFillPattern(FILLPATTERN_SOLID);
    xl.pivotRowColFmt->setPatternForegroundColor(COLOR_LIGHTYELLOW);

    // Подсветка опорного элемента
    xl.pivotElemFmt = xl.book->addFormat();
    xl.pivotElemFmt->setFont(boldFont);
    xl.pivotElemFmt->setNumFormat(customNumFmt);
    xl.pivotElemFmt->setBorder(BORDERSTYLE_THIN);
    xl.pivotElemFmt->setFillPattern(FILLPATTERN_SOLID);
    xl.pivotElemFmt->setPatternForegroundColor(COLOR_LIGHTGREEN);

    return true;
}

// =====================================================
// ЗАПИСЬ ТАБЛИЦЫ В EXCEL
// =====================================================

void write_tableau_to_excel(ExcelContext& xl,
                            const wstring& title,
                            int pivot_row = -1,
                            int pivot_col = -1)
{
    if (!xl.sheet)
        return;

    xl.sheet->writeStr(xl.row, 0, title.c_str(), xl.titleFmt);
    xl.row++;

    int cols = (int)matrix[0].size();
    xl.sheet->writeStr(xl.row, 0, L"Базис", xl.headerFmt);

    for (int j = 0; j < cols - 1; j++)
    {
        wstring col_name = L"x" + to_wstring(j + 1);
        xl.sheet->writeStr(xl.row, j + 1, col_name.c_str(), xl.headerFmt);
    }
    xl.sheet->writeStr(xl.row, cols, L"b", xl.headerFmt);
    xl.row++;

    int m = (int)matrix.size() - 1;
    for (int i = 0; i <= m; i++)
    {
        if (i < m)
        {
            wstring basis_name = L"x" + to_wstring(basis[i] + 1);
            xl.sheet->writeStr(xl.row, 0, basis_name.c_str(), xl.headerFmt);
        }
        else
        {
            xl.sheet->writeStr(xl.row, 0, L"F", xl.headerFmt);
        }

        for (int j = 0; j < cols; j++)
        {
            Format* cellFmt = xl.numFmt;

            if (i == pivot_row && j == pivot_col)
                cellFmt = xl.pivotElemFmt;
            else if ((pivot_row != -1 && i == pivot_row) ||
                     (pivot_col != -1 && j == pivot_col))
                cellFmt = xl.pivotRowColFmt;

            xl.sheet->writeNum(xl.row, j + 1, matrix[i][j], cellFmt);
        }
        xl.row++;
    }

    xl.row++;
}

// =====================================================
// ЧТЕНИЕ ЗАДАЧИ ИЗ ФАЙЛА
// =====================================================

bool read_problem(const string& filename, LPProblem& p)
{
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл\n";
        return false;
    }

    string type;
    fin >> type;

    if (type != "max" && type != "min")
    {
        cout << "Первая строка должна быть max или min\n";
        return false;
    }

    p.maximize = (type == "max");

    string line;
    getline(fin, line);

    if (!getline(fin, line))
    {
        cout << "Отсутствует целевая функция\n";
        return false;
    }

    istringstream obj_stream(line);
    double value;

    while (obj_stream >> value)
        p.objective.push_back(value);

    if (p.objective.empty())
    {
        cout << "Целевая функция пуста\n";
        return false;
    }

    p.n = (int)p.objective.size();

    while (getline(fin, line))
    {
        if (line.empty())
            continue;

        istringstream row_stream(line);

        Constraint c;
        c.a.resize(p.n);

        for (int j = 0; j < p.n; j++)
        {
            if (!(row_stream >> c.a[j]))
            {
                cout << "Недостаточно коэффициентов в ограничении\n";
                return false;
            }
        }

        if (!(row_stream >> c.sign >> c.b))
        {
            cout << "Неверный формат ограничения\n";
            return false;
        }

        if (c.sign != "<=" &&
            c.sign != ">=" &&
            c.sign != "=")
        {
            cout << "Неизвестный знак ограничения\n";
            return false;
        }

        p.constraints.push_back(c);
    }

    p.m = (int)p.constraints.size();

    if (p.m == 0)
    {
        cout << "Ограничения отсутствуют\n";
        return false;
    }

    return true;
}

// =====================================================
// ПЕЧАТЬ МАТРИЦЫ В КОНСОЛЬ
// =====================================================

void print_matrix()
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << setw(12) << fixed << setprecision(3)
                 << matrix[i][j];
        }
        cout << '\n';
    }
}

// =====================================================
// ПОСТРОЕНИЕ КАНОНИЧЕСКОЙ МАТРИЦЫ
// =====================================================

void build_tableau(const LPProblem& p)
{
    n_original = p.n;
    n_total = n_original;

    matrix.clear();
    basis.clear();
    artificials.clear();

    vector<vector<double>> rows;
    vector<double> rhs;
    vector<string> signs;

    for (int i = 0; i < p.m; i++)
    {
        vector<double> row = p.constraints[i].a;
        double b = p.constraints[i].b;
        string sign = p.constraints[i].sign;

        if (b < 0)
        {
            for (double& x : row)
                x = -x;

            b = -b;

            if (sign == "<=")
                sign = ">=";
            else if (sign == ">=")
                sign = "<=";
        }

        rows.push_back(row);
        rhs.push_back(b);
        signs.push_back(sign);
    }

    for (int i = 0; i < p.m; i++)
    {
        if (signs[i] == "<=")
            n_total++;
        else if (signs[i] == ">=")
            n_total += 2;
        else
            n_total++;
    }

    matrix.assign(p.m + 1,
                  vector<double>(n_total + 1, 0.0));

    for (int i = 0; i < p.m; i++)
    {
        for (int j = 0; j < n_original; j++)
            matrix[i][j] = rows[i][j];

        matrix[i][n_total] = rhs[i];
    }

    int col = n_original;

    for (int i = 0; i < p.m; i++)
    {
        if (signs[i] == "<=")
        {
            matrix[i][col] = 1.0;
            basis.push_back(col);
            col++;
        }
        else if (signs[i] == ">=")
        {
            matrix[i][col] = -1.0;
            col++;

            matrix[i][col] = 1.0;
            basis.push_back(col);
            artificials.push_back(col);
            col++;
        }
        else
        {
            matrix[i][col] = 1.0;
            basis.push_back(col);
            artificials.push_back(col);
            col++;
        }
    }
}

// =====================================================
// ОПЕРАЦИИ НАД СТРОКАМИ
// =====================================================

void divide_row(vector<double>& row, double value)
{
    for (double& x : row)
        x /= value;
}

void pivot(int i, int j)
{
    double value = matrix[i][j];

    divide_row(matrix[i], value);

    for (int k = 0; k < (int)matrix.size(); k++)
    {
        if (k == i)
            continue;

        double coeff = matrix[k][j];

        for (int c = 0; c < (int)matrix[k].size(); c++)
            matrix[k][c] -= coeff * matrix[i][c];
    }

    basis[i] = j;
}

// =====================================================
// ВЫБОР РАЗРЕШАЮЩЕГО СТОЛБЦА И СТРОКИ
// =====================================================

size_t is_negative(const vector<double>& row)
{
    size_t index = size_t(-1);
    double min_value = -EPS;

    for (size_t j = 0; j + 1 < row.size(); j++)
    {
        if (row[j] < min_value)
        {
            min_value = row[j];
            index = j;
        }
    }

    return index;
}

size_t is_positive(const vector<double>& row)
{
    size_t index = size_t(-1);
    double max_value = EPS;

    for (size_t j = 0; j + 1 < row.size(); j++)
    {
        if (row[j] > max_value)
        {
            max_value = row[j];
            index = j;
        }
    }

    return index;
}

size_t last_col_edit(size_t j)
{
    size_t pivot_row = size_t(-1);
    double min_ratio = 0.0;

    size_t last = matrix[0].size() - 1;

    for (size_t i = 0; i < matrix.size() - 1; i++)
    {
        double a = matrix[i][j];

        if (a <= EPS)
            continue;

        double ratio = matrix[i][last] / a;

        if (pivot_row == size_t(-1) ||
            ratio < min_ratio - EPS)
        {
            min_ratio = ratio;
            pivot_row = i;
        }
    }

    return pivot_row;
}

// =====================================================
// ФАЗА I
// =====================================================

void prepare_phase1()
{
    int m = (int)matrix.size() - 1;
    int last = (int)matrix[0].size() - 1;

    fill(matrix[m].begin(), matrix[m].end(), 0.0);

    for (int art : artificials)
        matrix[m][art] = 1.0;

    for (int i = 0; i < m; i++)
    {
        int b = basis[i];
        double coeff = matrix[m][b];

        if (abs(coeff) > EPS)
        {
            for (int j = 0; j <= last; j++)
                matrix[m][j] -= coeff * matrix[i][j];
        }
    }
}

bool phase1(ExcelContext& xl)
{
    cout << "\n========== ФАЗА I ==========\n";

    prepare_phase1();
    print_matrix();

    size_t last_row = matrix.size() - 1;
    int iter = 0;

    while (true)
    {
        size_t j = is_negative(matrix[last_row]);

        if (j == size_t(-1))
        {
            wstring title = L"Фаза I — Итерация " + to_wstring(iter) + L" (Оптимум Фазы I)";
            write_tableau_to_excel(xl, title);
            break;
        }

        size_t i = last_col_edit(j);

        if (i == size_t(-1))
        {
            write_tableau_to_excel(xl, L"Фаза I — Неограниченность", -1, (int)j);
            xl.sheet->writeStr(xl.row++, 0, L"Ошибка: неограниченность Фазы I", xl.statusFmt);
            cout << "Ошибка: неограниченность Фазы I\n";
            return false;
        }

        wstring title = (iter == 0)
            ? L"Фаза I — Начальная таблица"
            : L"Фаза I — Итерация " + to_wstring(iter);

        write_tableau_to_excel(xl, title, (int)i, (int)j);

        pivot((int)i, (int)j);
        iter++;

        print_matrix();
        cout << "------------------------------------\n";
    }

    double w = -matrix[last_row].back();

    cout << "Результат Фазы I: w = " << w << endl;

    if (w > EPS)
    {
        xl.sheet->writeStr(xl.row++, 0, L"Задача несовместна (w > 0)", xl.statusFmt);
        cout << "Задача несовместна\n";
        return false;
    }

    cout << "Фаза I успешно завершена\n";
    return true;
}

// =====================================================
// УДАЛЕНИЕ ИСКУССТВЕННЫХ ПЕРЕМЕННЫХ ИЗ БАЗИСА
// =====================================================

bool remove_artificial_basis(ExcelContext& xl)
{
    int m = (int)matrix.size() - 1;

    for (int i = 0; i < m; i++)
    {
        bool is_artificial =
            find(artificials.begin(),
                 artificials.end(),
                 basis[i]) != artificials.end();

        if (!is_artificial)
            continue;

        bool replaced = false;

        for (int j = 0; j < n_total; j++)
        {
            if (find(artificials.begin(),
                     artificials.end(),
                     j) != artificials.end())
                continue;

            if (abs(matrix[i][j]) > EPS)
            {
                pivot(i, j);
                replaced = true;
                break;
            }
        }

        if (!replaced)
        {
            bool zero_row = true;

            for (int j = 0; j < n_total; j++)
            {
                if (abs(matrix[i][j]) > EPS)
                {
                    zero_row = false;
                    break;
                }
            }

            if (zero_row &&
                abs(matrix[i].back()) <= EPS)
            {
                matrix.erase(matrix.begin() + i);
                basis.erase(basis.begin() + i);
                m--;
                i--;
            }
            else
            {
                xl.sheet->writeStr(xl.row++, 0, L"Не удалось удалить искусственную переменную", xl.statusFmt);
                cout << "Не удалось удалить искусственную переменную\n";
                return false;
            }
        }
    }

    return true;
}

// =====================================================
// ПОДГОТОВКА ФАЗЫ II
// =====================================================

void prepare_phase2(const vector<double>& objective,
                    bool maximize)
{
    int m = (int)matrix.size() - 1;

    sort(artificials.rbegin(), artificials.rend());

    for (int art : artificials)
    {
        for (int i = 0; i <= m; i++)
            matrix[i].erase(matrix[i].begin() + art);

        for (int& b : basis)
        {
            if (b > art)
                b--;
        }

        n_total--;
    }

    artificials.clear();

    int last = (int)matrix[0].size() - 1;

    fill(matrix[m].begin(), matrix[m].end(), 0.0);

    for (int j = 0; j < n_original; j++)
    {
        matrix[m][j] =
            maximize ? -objective[j] : objective[j];
    }

    for (int i = 0; i < m; i++)
    {
        int b = basis[i];
        double coeff = matrix[m][b];

        if (abs(coeff) > EPS)
        {
            for (int j = 0; j <= last; j++)
                matrix[m][j] -= coeff * matrix[i][j];
        }
    }
}

// =====================================================
// СИМПЛЕКС-МЕТОД (ФАЗА II)
// =====================================================

bool simplex(bool maximize, ExcelContext& xl)
{
    cout << "\n========== ФАЗА II ==========\n";

    print_matrix();

    size_t last_row = matrix.size() - 1;
    int iter = 0;

    while (true)
    {
        size_t j = maximize
            ? is_negative(matrix[last_row])
            : is_positive(matrix[last_row]);

        if (j == size_t(-1))
        {
            wstring title = L"Фаза II — Итерация " + to_wstring(iter) + L" (Оптимальная таблица)";
            write_tableau_to_excel(xl, title);
            break;
        }

        size_t i = last_col_edit(j);

        if (i == size_t(-1))
        {
            write_tableau_to_excel(xl, L"Фаза II — Задача не ограничена", -1, (int)j);
            xl.sheet->writeStr(xl.row++, 0, L"Задача не ограничена", xl.statusFmt);
            cout << "Задача не ограничена\n";
            return false;
        }

        wstring title = (iter == 0)
            ? L"Фаза II — Начальная таблица"
            : L"Фаза II — Итерация " + to_wstring(iter);

        // Записываем текущую таблицу ДО шага pivot, подсвечивая выбранные строку i и столбец j
        write_tableau_to_excel(xl, title, (int)i, (int)j);

        pivot((int)i, (int)j);
        iter++;

        print_matrix();
        cout << "------------------------------------\n";
    }

    return true;
}

// =====================================================
// ВЫВОД РЕШЕНИЯ
// =====================================================

void print_solution(bool maximize, ExcelContext& xl)
{
    int m = (int)matrix.size() - 1;
    int last = (int)matrix[0].size() - 1;

    vector<double> x(n_original, 0.0);

    for (int i = 0; i < m; i++)
    {
        if (basis[i] < n_original)
            x[basis[i]] = matrix[i][last];
    }

    cout << "\n========== РЕШЕНИЕ ==========\n";

    xl.sheet->writeStr(xl.row++, 0, L"Итоговое решение:", xl.titleFmt);

    for (int j = 0; j < n_original; j++)
    {
        cout << "x" << j + 1 << " = " << x[j] << endl;

        wstring var_name = L"x" + to_wstring(j + 1);
        xl.sheet->writeStr(xl.row, 0, var_name.c_str(), xl.headerFmt);
        xl.sheet->writeNum(xl.row, 1, x[j], xl.numFmt);
        xl.row++;
    }

    double result = matrix[m][last];

    if (!maximize)
        result = -result;

    cout << "Оптимальное значение F = " << result << endl;

    xl.sheet->writeStr(xl.row, 0, L"F_opt", xl.headerFmt);
    xl.sheet->writeNum(xl.row, 1, result, xl.pivotElemFmt);
    xl.row++;
}

// =====================================================
// MAIN
// =====================================================

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF-8");

    LPProblem problem;

    if (!read_problem("input.txt", problem))
        return 1;

    ExcelContext xl;
    if (!init_excel(xl))
        return 1;

    build_tableau(problem);

    cout << "\nНачальная таблица:\n";
    print_matrix();

    int max_cols = n_total + 1;

    if (!artificials.empty())
    {
        if (!phase1(xl) || !remove_artificial_basis(xl))
        {
            xl.sheet->setCol(0, max_cols, 13);
            xl.book->save(L"solution.xlsx");
            xl.book->release();
            return 0;
        }
    }

    prepare_phase2(problem.objective, problem.maximize);

    if (simplex(problem.maximize, xl))
    {
        print_solution(problem.maximize, xl);
    }

    xl.sheet->setCol(0, max_cols, 13);

    if (xl.book->save(L"solution.xlsx"))
        cout << "\nТаблица итераций сохранена в solution.xlsx\n";
    else
        cout << "\nОшибка сохранения Excel: " << xl.book->errorMessage() << endl;

    xl.book->release();

    return 0;
}