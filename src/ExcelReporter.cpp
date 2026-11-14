#include "ExcelReporter.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace libxl;

ExcelReporter::ExcelReporter() = default;

ExcelReporter::~ExcelReporter()
{
    if (book_)
    {
        book_->release();
        book_ = nullptr;
    }
}

bool ExcelReporter::init()
{
    book_ = xlCreateXMLBook();
    if (!book_)
        return false;

    // При наличии лицензионного ключа:
    // book_->setKey(L"Имя", L"Ключ");

    titleSheet_ = book_->addSheet(L"Титульный лист");
    processSheet_ = book_->addSheet(L"Процесс решения");
    resultSheet_ = book_->addSheet(L"Результаты");

    if (!titleSheet_ || !processSheet_ || !resultSheet_)
        return false;

    setupFormats();
    return true;
}

void ExcelReporter::setupFormats()
{
    Font* fH1 = book_->addFont();
    fH1->setBold(true);
    fH1->setSize(14);

    Font* fH2 = book_->addFont();
    fH2->setBold(true);
    fH2->setSize(11);

    Font* fBold = book_->addFont();
    fBold->setBold(true);

    h1Fmt_ = book_->addFormat();
    h1Fmt_->setFont(fH1);

    h2Fmt_ = book_->addFormat();
    h2Fmt_->setFont(fH2);

    boldFmt_ = book_->addFormat();
    boldFmt_->setFont(fBold);

    textFmt_ = book_->addFormat();
    textFmt_->setWrap(true);

    tableHeaderFmt_ = book_->addFormat();
    tableHeaderFmt_->setFont(fBold);
    tableHeaderFmt_->setAlignH(ALIGNH_CENTER);
    tableHeaderFmt_->setBorder(BORDERSTYLE_THIN);
    tableHeaderFmt_->setFillPattern(FILLPATTERN_SOLID);
    tableHeaderFmt_->setPatternForegroundColor(COLOR_GRAY25);

    int numFormatId = book_->addCustomNumFormat(L"0.000");

    numFmt_ = book_->addFormat();
    numFmt_->setNumFormat(numFormatId);
    numFmt_->setBorder(BORDERSTYLE_THIN);

    pivotRowColFmt_ = book_->addFormat();
    pivotRowColFmt_->setNumFormat(numFormatId);
    pivotRowColFmt_->setBorder(BORDERSTYLE_THIN);
    pivotRowColFmt_->setFillPattern(FILLPATTERN_SOLID);
    pivotRowColFmt_->setPatternForegroundColor(COLOR_LIGHTYELLOW);

    pivotElemFmt_ = book_->addFormat();
    pivotElemFmt_->setFont(fBold);
    pivotElemFmt_->setNumFormat(numFormatId);
    pivotElemFmt_->setBorder(BORDERSTYLE_THIN);
    pivotElemFmt_->setFillPattern(FILLPATTERN_SOLID);
    pivotElemFmt_->setPatternForegroundColor(COLOR_LIGHTGREEN);

    resultFmt_ = book_->addFormat();
    resultFmt_->setFont(fBold);
    resultFmt_->setNumFormat(numFormatId);
    resultFmt_->setBorder(BORDERSTYLE_MEDIUM);
    resultFmt_->setFillPattern(FILLPATTERN_SOLID);
    resultFmt_->setPatternForegroundColor(COLOR_LIGHTGREEN);
}

wstring ExcelReporter::formatLinearExpr(const vector<double>& coeffs)
{
    wostringstream wss;
    wss << fixed << setprecision(2);
    bool first = true;

    for (size_t j = 0; j < coeffs.size(); j++)
    {
        double val = coeffs[j];
        if (abs(val) <= EPS)
            continue;

        if (!first)
            wss << (val >= 0 ? L" + " : L" - ");
        else if (val < 0)
            wss << L"-";

        wss << abs(val) << L"*x" << (j + 1);
        first = false;
    }

    if (first)
        wss << L"0";

    return wss.str();
}

void ExcelReporter::writeTitleSheet(const LPProblem& problem,
                                    int n_total,
                                    const vector<int>& artificials)
{
    int r = 0;

    titleSheet_->writeStr(r++, 0, L"Лабораторная работа № 1 по курсу «Математическое программирование и оптимальное управление»", h1Fmt_);
    titleSheet_->writeStr(r++, 0, L"Тема: Реализация симплекс-метода для решения задач линейного программирования", h2Fmt_);
    r++;

    titleSheet_->writeStr(r++, 0, L"1. Постановка задачи", h2Fmt_);
    titleSheet_->writeStr(r++, 0, L"Найти оптимальный план X = (x1, x2, ..., xn), доставляющий экстремум линейной целевой функции при заданной системе линейных ограничений и условии неотрицательности переменных xj >= 0.", textFmt_);
    r++;

    titleSheet_->writeStr(r++, 0, L"2. Исходные данные задачи", h2Fmt_);

    titleSheet_->writeStr(r, 0, L"Тип задачи (критерий):", boldFmt_);
    titleSheet_->writeStr(r++, 1, problem.maximize ? L"Максимизация (max)" : L"Минимизация (min)");

    titleSheet_->writeStr(r, 0, L"Количество исходных переменных (n):", boldFmt_);
    titleSheet_->writeNum(r++, 1, problem.n);

    titleSheet_->writeStr(r, 0, L"Количество ограничений (m):", boldFmt_);
    titleSheet_->writeNum(r++, 1, problem.m);

    wstring objStr = L"F(X) = " + formatLinearExpr(problem.objective) +
                     (problem.maximize ? L" -> max" : L" -> min");
    titleSheet_->writeStr(r, 0, L"Целевая функция:", boldFmt_);
    titleSheet_->writeStr(r++, 1, objStr.c_str());
    r++;

    titleSheet_->writeStr(r++, 0, L"Система ограничений:", boldFmt_);
    for (int i = 0; i < problem.m; i++)
    {
        wostringstream cStr;
        cStr << formatLinearExpr(problem.constraints[i].a) << L" ";
        string s = problem.constraints[i].sign;
        cStr << wstring(s.begin(), s.end()) << L" " << fixed << setprecision(2) << problem.constraints[i].b;

        wstring label = L"Ограничение " + to_wstring(i + 1) + L":";
        titleSheet_->writeStr(r, 0, label.c_str(), boldFmt_);
        titleSheet_->writeStr(r++, 1, cStr.str().c_str());
    }
    r++;

    titleSheet_->writeStr(r++, 0, L"3. Сведения о приведении к канонической форме", h2Fmt_);
    titleSheet_->writeStr(r, 0, L"Всего переменных после введения балансовых/искусственных:", boldFmt_);
    titleSheet_->writeNum(r++, 1, n_total);

    titleSheet_->writeStr(r, 0, L"Метод решения:", boldFmt_);
    if (artificials.empty())
        titleSheet_->writeStr(r++, 1, L"Однофазный симплекс-метод (начальный допустимый базис очевиден)");
    else
        titleSheet_->writeStr(r++, 1, L"Двухфазный симплекс-метод (введены искусственные переменные для построения начального базиса)");

    titleSheet_->setCol(0, 0, 48);
    titleSheet_->setCol(1, 1, 55);
}

void ExcelReporter::writeStepComment(const wstring& comment)
{
    processSheet_->writeStr(processRow_++, 0, comment.c_str(), textFmt_);
}

void ExcelReporter::writeTableau(const wstring& title,
                                 const vector<vector<double>>& matrix,
                                 const vector<int>& basis,
                                 int pivot_row,
                                 int pivot_col)
{
    processSheet_->writeStr(processRow_++, 0, title.c_str(), h2Fmt_);

    int cols = static_cast<int>(matrix[0].size());
    maxProcessCols_ = max(maxProcessCols_, cols + 1);

    processSheet_->writeStr(processRow_, 0, L"Базис", tableHeaderFmt_);
    for (int j = 0; j < cols - 1; j++)
    {
        wstring col_name = L"x" + to_wstring(j + 1);
        processSheet_->writeStr(processRow_, j + 1, col_name.c_str(), tableHeaderFmt_);
    }
    processSheet_->writeStr(processRow_, cols, L"b (Прав. часть)", tableHeaderFmt_);
    processRow_++;

    int m = static_cast<int>(matrix.size()) - 1;
    for (int i = 0; i <= m; i++)
    {
        if (i < m)
        {
            wstring basis_name = L"x" + to_wstring(basis[i] + 1);
            processSheet_->writeStr(processRow_, 0, basis_name.c_str(), tableHeaderFmt_);
        }
        else
        {
            processSheet_->writeStr(processRow_, 0, L"Оценки F", tableHeaderFmt_);
        }

        for (int j = 0; j < cols; j++)
        {
            Format* fmt = numFmt_;
            if (i == pivot_row && j == pivot_col)
                fmt = pivotElemFmt_;
            else if ((pivot_row != -1 && i == pivot_row) ||
                     (pivot_col != -1 && j == pivot_col))
                fmt = pivotRowColFmt_;

            processSheet_->writeNum(processRow_, j + 1, matrix[i][j], fmt);
        }
        processRow_++;
    }

    processRow_++;
}

void ExcelReporter::writeResultsSheet(SolveStatus status,
                                      const wstring& status_details,
                                      const vector<double>& solution,
                                      double objective_value)
{
    int r = 0;

    resultSheet_->writeStr(r++, 0, L"Итоговый отчет о решении задачи линейного программирования", h1Fmt_);
    r++;

    resultSheet_->writeStr(r, 0, L"Статус решения:", boldFmt_);
    resultSheet_->writeStr(r++, 1, status_details.c_str(), boldFmt_);
    r++;

    if (status == SolveStatus::Optimal)
    {
        resultSheet_->writeStr(r++, 0, L"Оптимальная точка (значения переменных):", h2Fmt_);
        resultSheet_->writeStr(r, 0, L"Переменная", tableHeaderFmt_);
        resultSheet_->writeStr(r++, 1, L"Значение", tableHeaderFmt_);

        for (size_t j = 0; j < solution.size(); j++)
        {
            wstring varName = L"x" + to_wstring(j + 1);
            resultSheet_->writeStr(r, 0, varName.c_str(), tableHeaderFmt_);
            resultSheet_->writeNum(r++, 1, solution[j], numFmt_);
        }

        r++;
        resultSheet_->writeStr(r, 0, L"Оптимальное значение целевой функции F*:", boldFmt_);
        resultSheet_->writeNum(r++, 1, objective_value, resultFmt_);
    }
    else
    {
        resultSheet_->writeStr(r++, 0, L"Оптимальное решение не существует. Подробная трассировка итераций приведена на листе «Процесс решения».", textFmt_);
    }

    resultSheet_->setCol(0, 0, 42);
    resultSheet_->setCol(1, 1, 35);
}

bool ExcelReporter::save(const wstring& filename)
{
    processSheet_->setCol(0, 0, 16);
    processSheet_->setCol(1, maxProcessCols_, 14);
    return book_->save(filename.c_str());
}