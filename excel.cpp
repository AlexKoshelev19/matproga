
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const float EPS = 1e-6f;

struct Constraint {
    vector<float> a;
    string sign;
    float b;
};

struct LPProblem {
    int n = 0;
    int m = 0;
    bool maximize = true;
    vector<float> objective;
    vector<Constraint> constraints;
};

vector<vector<float>> matrix;
vector<int> basis;
vector<int> artificials;

int n_original = 0;
int n_total = 0;

// =====================================================
// ЧТЕНИЕ ЗАДАЧИ ИЗ ФАЙЛА
// =====================================================

bool read_problem(const string& filename, LPProblem& p)
{
    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Не удалось открыть файл\n";
        return false;
    }

    string type;
    fin >> type;

    if (type != "max" && type != "min") {
        cout << "Первая строка должна быть max или min\n";
        return false;
    }

    p.maximize = (type == "max");

    string line;
    getline(fin, line);

    // Целевая функция
    if (!getline(fin, line)) {
        cout << "Отсутствует целевая функция\n";
        return false;
    }

    istringstream obj_stream(line);
    float value;

    while (obj_stream >> value)
        p.objective.push_back(value);

    if (p.objective.empty()) {
        cout << "Целевая функция пуста\n";
        return false;
    }

    p.n = (int)p.objective.size();

    // Ограничения
    while (getline(fin, line)) {
        if (line.empty())
            continue;

        istringstream row_stream(line);

        Constraint c;
        c.a.resize(p.n);

        for (int j = 0; j < p.n; j++) {
            if (!(row_stream >> c.a[j])) {
                cout << "Недостаточно коэффициентов в ограничении\n";
                return false;
            }
        }

        if (!(row_stream >> c.sign >> c.b)) {
            cout << "Неверный формат ограничения\n";
            return false;
        }

        if (c.sign != "<=" &&
            c.sign != ">=" &&
            c.sign != "=") {
            cout << "Неизвестный знак ограничения\n";
            return false;
        }

        p.constraints.push_back(c);
    }

    p.m = (int)p.constraints.size();

    if (p.m == 0) {
        cout << "Ограничения отсутствуют\n";
        return false;
    }

    return true;
}

// =====================================================
// ПЕЧАТЬ МАТРИЦЫ
// =====================================================

void print_matrix()
{
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
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

    vector<vector<float>> rows;
    vector<float> rhs;
    vector<string> signs;

    // Нормализация RHS
    for (int i = 0; i < p.m; i++) {
        vector<float> row = p.constraints[i].a;
        float b = p.constraints[i].b;
        string sign = p.constraints[i].sign;

        if (b < 0) {
            for (float& x : row)
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

    // Подсчёт дополнительных переменных
    for (int i = 0; i < p.m; i++) {
        if (signs[i] == "<=") {
            n_total++;
        }
        else if (signs[i] == ">=") {
            n_total += 2;
        }
        else {
            n_total++;
        }
    }

    // Создание матрицы
    matrix.assign(p.m + 1,
                  vector<float>(n_total + 1, 0));

    // Заполняем исходные коэффициенты
    for (int i = 0; i < p.m; i++) {
        for (int j = 0; j < n_original; j++)
            matrix[i][j] = rows[i][j];

        matrix[i][n_total] = rhs[i];
    }

    // Добавление slack, surplus и artificial
    int col = n_original;

    for (int i = 0; i < p.m; i++) {
        if (signs[i] == "<=") {
            matrix[i][col] = 1;
            basis.push_back(col);
            col++;
        }
        else if (signs[i] == ">=") {
            matrix[i][col] = -1;
            col++;

            matrix[i][col] = 1;
            basis.push_back(col);
            artificials.push_back(col);
            col++;
        }
        else {
            matrix[i][col] = 1;
            basis.push_back(col);
            artificials.push_back(col);
            col++;
        }
    }
}

// =====================================================
// ОПЕРАЦИИ НАД СТРОКАМИ
// =====================================================

void divide_row(vector<float>& row, float value)
{
    for (float& x : row)
        x /= value;
}

void pivot(int i, int j)
{
    float value = matrix[i][j];

    divide_row(matrix[i], value);

    for (int k = 0; k < (int)matrix.size(); k++) {
        if (k == i)
            continue;

        float coeff = matrix[k][j];

        for (int c = 0; c < (int)matrix[k].size(); c++)
            matrix[k][c] -= coeff * matrix[i][c];
    }

    basis[i] = j;
}

// =====================================================
// ВЫБОР РАЗРЕШАЮЩЕГО СТОЛБЦА
// =====================================================

size_t is_negative(const vector<float>& row)
{
    size_t index = size_t(-1);
    float min_value = -EPS;

    for (size_t j = 0; j + 1 < row.size(); j++) {
        if (row[j] < min_value) {
            min_value = row[j];
            index = j;
        }
    }

    return index;
}

size_t is_positive(const vector<float>& row)
{
    size_t index = size_t(-1);
    float max_value = EPS;

    for (size_t j = 0; j + 1 < row.size(); j++) {
        if (row[j] > max_value) {
            max_value = row[j];
            index = j;
        }
    }

    return index;
}

// =====================================================
// ВЫБОР РАЗРЕШАЮЩЕЙ СТРОКИ
// =====================================================

size_t last_col_edit(size_t j)
{
    size_t pivot_row = size_t(-1);
    float min_ratio = 0;

    size_t last = matrix[0].size() - 1;

    for (size_t i = 0; i < matrix.size() - 1; i++) {
        float a = matrix[i][j];

        if (a <= EPS)
            continue;

        float ratio = matrix[i][last] / a;

        if (pivot_row == size_t(-1) ||
            ratio < min_ratio - EPS) {
            min_ratio = ratio;
            pivot_row = i;
        }
    }

    return pivot_row;
}

// =====================================================
// ФАЗА I: ПОДГОТОВКА ЦЕЛЕВОЙ ФУНКЦИИ
// max(-w)
// =====================================================

void prepare_phase1()
{
    int m = (int)matrix.size() - 1;
    int last = (int)matrix[0].size() - 1;

    fill(matrix[m].begin(), matrix[m].end(), 0.0f);

    // Коэффициенты artificial переменных в max(-w)
    for (int art : artificials)
        matrix[m][art] = 1;

    // Приведение к текущему базису
    for (int i = 0; i < m; i++) {
        int b = basis[i];
        float coeff = matrix[m][b];

        if (abs(coeff) > EPS) {
            for (int j = 0; j <= last; j++)
                matrix[m][j] -= coeff * matrix[i][j];
        }
    }
}

// =====================================================
// ФАЗА I
// =====================================================

bool phase1()
{
    cout << "\n========== ФАЗА I ==========\n";

    prepare_phase1();
    print_matrix();

    size_t last_row = matrix.size() - 1;

    while (true) {
        size_t j = is_negative(matrix[last_row]);

        if (j == size_t(-1))
            break;

        size_t i = last_col_edit(j);

        if (i == size_t(-1)) {
            cout << "Ошибка: неограниченность Фазы I\n";
            return false;
        }

        pivot((int)i, (int)j);

        print_matrix();
        cout << "------------------------------------\n";
    }

    // Для max(-w) RHS = -w
    float w = -matrix[last_row].back();

    cout << "Результат Фазы I: w = "
         << w << endl;

    if (w > EPS) {
        cout << "Задача несовместна\n";
        return false;
    }

    cout << "Фаза I успешно завершена\n";
    return true;
}

// =====================================================
// УДАЛЕНИЕ ИСКУССТВЕННЫХ ПЕРЕМЕННЫХ ИЗ БАЗИСА
// =====================================================

bool remove_artificial_basis()
{
    int m = (int)matrix.size() - 1;

    for (int i = 0; i < m; i++) {
        bool is_artificial =
            find(artificials.begin(),
                 artificials.end(),
                 basis[i]) != artificials.end();

        if (!is_artificial)
            continue;

        bool replaced = false;

        for (int j = 0; j < n_total; j++) {
            if (find(artificials.begin(),
                     artificials.end(),
                     j) != artificials.end())
                continue;

            if (abs(matrix[i][j]) > EPS) {
                pivot(i, j);
                replaced = true;
                break;
            }
        }

        if (!replaced) {
            // Проверяем, является ли строка избыточной
            bool zero_row = true;

            for (int j = 0; j < n_total; j++) {
                if (abs(matrix[i][j]) > EPS) {
                    zero_row = false;
                    break;
                }
            }

            if (zero_row &&
                abs(matrix[i].back()) <= EPS) {
                matrix.erase(matrix.begin() + i);
                basis.erase(basis.begin() + i);
                m--;
                i--;
            }
            else {
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

void prepare_phase2(const vector<float>& objective,
                    bool maximize)
{
    int m = (int)matrix.size() - 1;

    // Удаляем искусственные столбцы с конца
    sort(artificials.rbegin(), artificials.rend());

    for (int art : artificials) {
        for (int i = 0; i <= m; i++)
            matrix[i].erase(matrix[i].begin() + art);

        for (int& b : basis) {
            if (b > art)
                b--;
        }

        n_total--;
    }

    artificials.clear();

    int last = (int)matrix[0].size() - 1;

    // Восстанавливаем исходную целевую функцию
    fill(matrix[m].begin(), matrix[m].end(), 0.0f);

    for (int j = 0; j < n_original; j++) {
        matrix[m][j] =
            maximize ? -objective[j] : objective[j];
    }

    // Приведение строки цели к текущему базису
    for (int i = 0; i < m; i++) {
        int b = basis[i];
        float coeff = matrix[m][b];

        if (abs(coeff) > EPS) {
            for (int j = 0; j <= last; j++)
                matrix[m][j] -= coeff * matrix[i][j];
        }
    }
}

// =====================================================
// СИМПЛЕКС-МЕТОД
// =====================================================

bool simplex(bool maximize)
{
    cout << "\n========== ФАЗА II ==========\n";

    print_matrix();

    size_t last_row = matrix.size() - 1;

    while (true) {
        size_t j;

        if (maximize)
            j = is_negative(matrix[last_row]);
        else
            j = is_positive(matrix[last_row]);

        if (j == size_t(-1))
            break;

        size_t i = last_col_edit(j);

        if (i == size_t(-1)) {
            cout << "Задача не ограничена\n";
            return false;
        }

        pivot((int)i, (int)j);

        print_matrix();
        cout << "------------------------------------\n";
    }

    return true;
}

// =====================================================
// ВЫВОД РЕШЕНИЯ
// =====================================================

void print_solution(bool maximize)
{
    int m = (int)matrix.size() - 1;
    int last = (int)matrix[0].size() - 1;

    vector<float> x(n_original, 0);

    for (int i = 0; i < m; i++) {
        if (basis[i] < n_original)
            x[basis[i]] = matrix[i][last];
    }

    cout << "\n========== РЕШЕНИЕ ==========\n";

    for (int j = 0; j < n_original; j++)
        cout << "x" << j + 1 << " = " << x[j] << endl;

    float result = matrix[m][last];

    if (!maximize)
        result = -result;

    cout << "Оптимальное значение F = "
         << result << endl;
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

    build_tableau(problem);

    cout << "\nНачальная таблица:\n";
    print_matrix();

    // Если есть искусственные переменные
    if (!artificials.empty()) {
        if (!phase1())
            return 0;

        if (!remove_artificial_basis())
            return 0;
    }

    // Фаза II
    prepare_phase2(problem.objective,
                   problem.maximize);

    if (!simplex(true))
        return 0;

    print_solution(problem.maximize);

    return 0;
}
