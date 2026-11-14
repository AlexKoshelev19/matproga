#include "SimplexSolver.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

SimplexSolver::SimplexSolver(const LPProblem& problem)
    : problem_(problem)
{
}

void SimplexSolver::buildCanonicalTableau()
{
    n_original_ = problem_.n;
    n_total_ = n_original_;

    matrix_.clear();
    basis_.clear();
    artificials_.clear();

    vector<vector<double>> rows;
    vector<double> rhs;
    vector<string> signs;

    // Нормализация правых частей (b >= 0)
    for (int i = 0; i < problem_.m; i++)
    {
        vector<double> row = problem_.constraints[i].a;
        double b = problem_.constraints[i].b;
        string sign = problem_.constraints[i].sign;

        if (b < 0.0)
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

    for (int i = 0; i < problem_.m; i++)
        n_total_ += (signs[i] == ">=") ? 2 : 1;

    matrix_.assign(problem_.m + 1, vector<double>(n_total_ + 1, 0.0));

    for (int i = 0; i < problem_.m; i++)
    {
        for (int j = 0; j < n_original_; j++)
            matrix_[i][j] = rows[i][j];

        matrix_[i][n_total_] = rhs[i];
    }

    int col = n_original_;
    for (int i = 0; i < problem_.m; i++)
    {
        if (signs[i] == "<=")
        {
            matrix_[i][col] = 1.0;
            basis_.push_back(col++);
        }
        else if (signs[i] == ">=")
        {
            matrix_[i][col++] = -1.0;
            matrix_[i][col] = 1.0;
            basis_.push_back(col);
            artificials_.push_back(col++);
        }
        else
        {
            matrix_[i][col] = 1.0;
            basis_.push_back(col);
            artificials_.push_back(col++);
        }
    }
}

void SimplexSolver::updateObjectiveRow(const vector<double>& coeffs)
{
    int m = static_cast<int>(matrix_.size()) - 1;
    int last = static_cast<int>(matrix_[0].size()) - 1;

    fill(matrix_[m].begin(), matrix_[m].end(), 0.0);

    for (size_t j = 0; j < coeffs.size(); j++)
        matrix_[m][j] = coeffs[j];

    // Исключение базисных переменных из строки целевой функции
    for (int i = 0; i < m; i++)
    {
        int b = basis_[i];
        double coeff = matrix_[m][b];

        if (abs(coeff) > EPS)
        {
            for (int j = 0; j <= last; j++)
                matrix_[m][j] -= coeff * matrix_[i][j];
        }
    }
}

void SimplexSolver::pivot(int pivot_row, int pivot_col)
{
    double pivot_val = matrix_[pivot_row][pivot_col];

    for (double& x : matrix_[pivot_row])
        x /= pivot_val;

    for (size_t k = 0; k < matrix_.size(); k++)
    {
        if (static_cast<int>(k) == pivot_row)
            continue;

        double factor = matrix_[k][pivot_col];
        if (abs(factor) > EPS)
        {
            for (size_t c = 0; c < matrix_[k].size(); c++)
                matrix_[k][c] -= factor * matrix_[pivot_row][c];
        }
    }

    basis_[pivot_row] = pivot_col;
}

int SimplexSolver::findEnteringColumn(bool maximize_obj) const
{
    const auto& obj_row = matrix_.back();
    int best_col = -1;
    double best_val = EPS;

    for (size_t j = 0; j + 1 < obj_row.size(); j++)
    {
        double val = maximize_obj ? -obj_row[j] : obj_row[j];
        if (val > best_val)
        {
            best_val = val;
            best_col = static_cast<int>(j);
        }
    }

    return best_col;
}

int SimplexSolver::findLeavingRow(int pivot_col, double& min_ratio) const
{
    int best_row = -1;
    min_ratio = 0.0;
    size_t last = matrix_[0].size() - 1;

    for (size_t i = 0; i + 1 < matrix_.size(); i++)
    {
        double a = matrix_[i][pivot_col];
        if (a <= EPS)
            continue;

        double ratio = matrix_[i][last] / a;
        if (best_row == -1 || ratio < min_ratio - EPS)
        {
            min_ratio = ratio;
            best_row = static_cast<int>(i);
        }
    }

    return best_row;
}

SolveStatus SimplexSolver::runSimplexIterations(bool maximize_obj,
                                                const wstring& phase_name,
                                                ExcelReporter& reporter)
{
    int iter = 0;

    while (true)
    {
        int j = findEnteringColumn(maximize_obj);

        if (j == -1)
        {
            wstring title = phase_name + L": Итерация " + to_wstring(iter) + L" (Оптимальный план этапа)";
            reporter.writeTableau(title, matrix_, basis_);
            reporter.writeStepComment(L"Критерий оптимальности выполнен: улучшающих переменных в строке оценок нет.");
            printMatrixConsole();
            return SolveStatus::Optimal;
        }

        double min_ratio = 0.0;
        int i = findLeavingRow(j, min_ratio);

        if (i == -1)
        {
            wstring title = phase_name + L": Итерация " + to_wstring(iter) + L" (Обнаружена неограниченность)";
            reporter.writeTableau(title, matrix_, basis_, -1, j);

            wostringstream msg;
            msg << L"Переменная x" << (j + 1) << L" может расти неограниченно (все коэффициенты в столбце <= 0).";
            reporter.writeStepComment(msg.str());
            return SolveStatus::Unbounded;
        }

        wstring title = (iter == 0)
            ? phase_name + L": Начальная симплекс-таблица"
            : phase_name + L": Итерация " + to_wstring(iter);

        reporter.writeTableau(title, matrix_, basis_, i, j);

        wostringstream stepInfo;
        stepInfo << fixed << setprecision(3)
                 << L"Шаг " << (iter + 1) << L": в базис вводится x" << (j + 1)
                 << L", из базиса выводится x" << (basis_[i] + 1)
                 << L" (опорный элемент a[" << (i + 1) << L"," << (j + 1) << L"] = " << matrix_[i][j]
                 << L", min-отношение theta = " << min_ratio << L").";
        reporter.writeStepComment(stepInfo.str());

        printMatrixConsole();
        cout << "------------------------------------\n";

        pivot(i, j);
        iter++;
    }
}

bool SimplexSolver::removeArtificialBasis(ExcelReporter& reporter)
{
    int m = static_cast<int>(matrix_.size()) - 1;

    for (int i = 0; i < m; i++)
    {
        bool is_art = find(artificials_.begin(), artificials_.end(), basis_[i]) != artificials_.end();
        if (!is_art)
            continue;

        bool replaced = false;
        for (int j = 0; j < n_total_; j++)
        {
            if (find(artificials_.begin(), artificials_.end(), j) != artificials_.end())
                continue;

            if (abs(matrix_[i][j]) > EPS)
            {
                pivot(i, j);
                replaced = true;
                break;
            }
        }

        if (!replaced)
        {
            bool zero_row = true;
            for (int j = 0; j < n_total_; j++)
            {
                if (abs(matrix_[i][j]) > EPS)
                {
                    zero_row = false;
                    break;
                }
            }

            if (zero_row && abs(matrix_[i].back()) <= EPS)
            {
                matrix_.erase(matrix_.begin() + i);
                basis_.erase(basis_.begin() + i);
                m--;
                i--;
            }
            else
            {
                reporter.writeStepComment(L"Ошибка: не удалось вывести искусственную переменную из базиса.");
                return false;
            }
        }
    }

    return true;
}

void SimplexSolver::removeArtificialColumns()
{
    int m = static_cast<int>(matrix_.size()) - 1;
    sort(artificials_.rbegin(), artificials_.rend());

    for (int art : artificials_)
    {
        for (int i = 0; i <= m; i++)
            matrix_[i].erase(matrix_[i].begin() + art);

        for (int& b : basis_)
        {
            if (b > art)
                b--;
        }
        n_total_--;
    }

    artificials_.clear();
}

void SimplexSolver::extractOptimalSolution()
{
    int m = static_cast<int>(matrix_.size()) - 1;
    int last = static_cast<int>(matrix_[0].size()) - 1;

    solution_.assign(n_original_, 0.0);
    for (int i = 0; i < m; i++)
    {
        if (basis_[i] < n_original_)
            solution_[basis_[i]] = matrix_[i][last];
    }

    objectiveValue_ = problem_.maximize ? matrix_[m][last] : -matrix_[m][last];
}

void SimplexSolver::printMatrixConsole() const
{
    for (const auto& row : matrix_)
    {
        for (double val : row)
            cout << setw(10) << fixed << setprecision(3) << val;
        cout << '\n';
    }
}

SolveStatus SimplexSolver::solve(ExcelReporter& reporter)
{
    buildCanonicalTableau();
    reporter.writeTitleSheet(problem_, n_total_, artificials_);

    // Фаза I (если присутствуют искусственные переменные)
    if (!artificials_.empty())
    {
        cout << "\n========== ФАЗА I ==========\n";
        vector<double> phase1_obj(n_total_, 0.0);
        for (int art : artificials_)
            phase1_obj[art] = 1.0;

        updateObjectiveRow(phase1_obj);

        SolveStatus st1 = runSimplexIterations(true, L"Фаза I (Поиск допустимого базиса)", reporter);
        if (st1 != SolveStatus::Optimal)
        {
            statusMessage_ = L"Ошибка на Фазе I: вспомогательная задача не ограничена";
            return SolveStatus::Error;
        }

        double w = -matrix_.back().back();
        if (w > EPS)
        {
            statusMessage_ = L"Задача несовместна (система ограничений противоречива, w > 0)";
            reporter.writeStepComment(statusMessage_);
            return SolveStatus::Infeasible;
        }

        if (!removeArtificialBasis(reporter))
        {
            statusMessage_ = L"Задача несовместна (не удалось исключить искусственный базис)";
            return SolveStatus::Infeasible;
        }

        removeArtificialColumns();
    }

    // Фаза II (оптимизация исходной целевой функции)
    cout << "\n========== ФАЗА II ==========\n";
    vector<double> phase2_obj(n_total_, 0.0);
    for (int j = 0; j < n_original_; j++)
        phase2_obj[j] = problem_.maximize ? -problem_.objective[j] : problem_.objective[j];

    updateObjectiveRow(phase2_obj);

    SolveStatus st2 = runSimplexIterations(problem_.maximize, L"Фаза II (Оптимизация целевой функции)", reporter);

    if (st2 == SolveStatus::Unbounded)
    {
        statusMessage_ = L"Целевая функция не ограничена на множестве допустимых планов";
        return SolveStatus::Unbounded;
    }

    extractOptimalSolution();
    statusMessage_ = L"Оптимальное решение успешно найдено";
    return SolveStatus::Optimal;
}