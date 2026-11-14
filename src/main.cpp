#include "InputReader.hpp"
#include "SimplexSolver.hpp"
#include "ExcelReporter.hpp"
#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF-8");

    cout << "Выберите способ ввода исходных данных:\n";
    cout << "  1 — Загрузить из текстового файла (input.txt)\n";
    cout << "  2 — Ввести с клавиатуры\n";
    cout << "Ваш выбор: ";

    int mode = 1;
    if (!(cin >> mode))
        return 1;

    LPProblem problem;
    bool loaded = false;

    if (mode == 1)
    {
        loaded = InputReader::readFromFile("input.txt", problem);
    }
    else if (mode == 2)
    {
        loaded = InputReader::readFromConsole(problem);
    }
    else
    {
        cout << "Неизвестный пункт меню\n";
        return 1;
    }

    if (!loaded)
        return 1;

    ExcelReporter reporter;
    if (!reporter.init())
    {
        cout << "Ошибка инициализации библиотеки LibXL\n";
        return 1;
    }

    SimplexSolver solver(problem);
    SolveStatus status = solver.solve(reporter);

    reporter.writeResultsSheet(status,
                               solver.getStatusMessage(),
                               solver.getSolution(),
                               solver.getObjectiveValue());

    cout << "\n========== ИТОГ ==========\n";
    if (status == SolveStatus::Optimal)
    {
        const auto& sol = solver.getSolution();
        for (size_t j = 0; j < sol.size(); j++)
            cout << "x" << (j + 1) << " = " << sol[j] << '\n';

        cout << "Оптимальное значение F* = " << solver.getObjectiveValue() << '\n';
    }
    else if (status == SolveStatus::Infeasible)
    {
        cout << "Решение отсутствует: система ограничений несовместна.\n";
    }
    else if (status == SolveStatus::Unbounded)
    {
        cout << "Решение отсутствует: целевая функция не ограничена.\n";
    }

    if (reporter.save(L"solution.xlsx"))
        cout << "Подробный отчет сохранен в файл solution.xlsx\n";
    else
        cout << "Ошибка сохранения файла solution.xlsx\n";

    return 0;
}