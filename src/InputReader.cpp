#include "InputReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

bool InputReader::readFromFile(const string& filename, LPProblem& p)
{
    p = LPProblem{};
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "Ошибка: не удалось открыть файл \"" << filename << "\"\n";
        return false;
    }

    string type;
    if (!(fin >> type) || (type != "max" && type != "min"))
    {
        cout << "Ошибка: первая строка файла должна быть max или min\n";
        return false;
    }

    p.maximize = (type == "max");

    string line;
    getline(fin, line);

    while (getline(fin, line) && line.find_first_not_of(" \t\r\n") == string::npos)
    {
    }

    istringstream obj_stream(line);
    double value = 0.0;
    while (obj_stream >> value)
        p.objective.push_back(value);

    if (p.objective.empty())
    {
        cout << "Ошибка: целевая функция пуста\n";
        return false;
    }

    p.n = static_cast<int>(p.objective.size());

    while (getline(fin, line))
    {
        if (line.find_first_not_of(" \t\r\n") == string::npos)
            continue;

        istringstream row_stream(line);
        Constraint c;
        c.a.resize(p.n);

        for (int j = 0; j < p.n; j++)
        {
            if (!(row_stream >> c.a[j]))
            {
                cout << "Ошибка: недостаточно коэффициентов в ограничении\n";
                return false;
            }
        }

        if (!(row_stream >> c.sign >> c.b) ||
            (c.sign != "<=" && c.sign != ">=" && c.sign != "="))
        {
            cout << "Ошибка: неверный формат знака или правой части ограничения\n";
            return false;
        }

        p.constraints.push_back(c);
    }

    p.m = static_cast<int>(p.constraints.size());
    if (p.m == 0)
    {
        cout << "Ошибка: ограничения отсутствуют\n";
        return false;
    }

    return true;
}

bool InputReader::readFromConsole(LPProblem& p)
{
    p = LPProblem{};

    string type;
    cout << "Введите направление оптимизации (max / min): ";
    cin >> type;

    if (type != "max" && type != "min")
    {
        cout << "Ошибка: допустимы только значения max или min\n";
        return false;
    }
    p.maximize = (type == "max");

    cout << "Введите количество переменных n: ";
    if (!(cin >> p.n) || p.n <= 0)
    {
        cout << "Ошибка: некорректное количество переменных\n";
        return false;
    }

    cout << "Введите количество ограничений m: ";
    if (!(cin >> p.m) || p.m <= 0)
    {
        cout << "Ошибка: некорректное количество ограничений\n";
        return false;
    }

    p.objective.resize(p.n);
    cout << "Введите коэффициенты целевой функции (c1 ... c" << p.n << "): ";
    for (int j = 0; j < p.n; j++)
    {
        if (!(cin >> p.objective[j]))
        {
            cout << "Ошибка ввода коэффициентов целевой функции\n";
            return false;
        }
    }

    cout << "Введите ограничения в формате: a1 a2 ... an знак(<=, >=, =) b\n";
    for (int i = 0; i < p.m; i++)
    {
        cout << "Ограничение " << i + 1 << ": ";
        Constraint c;
        c.a.resize(p.n);

        for (int j = 0; j < p.n; j++)
        {
            if (!(cin >> c.a[j]))
            {
                cout << "Ошибка ввода коэффициентов ограничения\n";
                return false;
            }
        }

        if (!(cin >> c.sign >> c.b) ||
            (c.sign != "<=" && c.sign != ">=" && c.sign != "="))
        {
            cout << "Ошибка: неверный знак (ожидается <=, >= или =) или правая часть\n";
            return false;
        }

        p.constraints.push_back(c);
    }

    return true;
}