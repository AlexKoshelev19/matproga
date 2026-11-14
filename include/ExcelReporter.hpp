#pragma once

#include "LPModels.hpp"
#include "libxl.h"
#include <vector>
#include <string>

class ExcelReporter
{
public:
    ExcelReporter();
    ~ExcelReporter();

    bool init();
    void writeTitleSheet(const LPProblem& problem,
                         int n_total,
                         const std::vector<int>& artificials);

    void writeStepComment(const std::wstring& comment);
    void writeTableau(const std::wstring& title,
                      const std::vector<std::vector<double>>& matrix,
                      const std::vector<int>& basis,
                      int pivot_row = -1,
                      int pivot_col = -1);

    void writeResultsSheet(SolveStatus status,
                           const std::wstring& status_details,
                           const std::vector<double>& solution,
                           double objective_value);

    bool save(const std::wstring& filename);

private:
    libxl::Book* book_ = nullptr;
    libxl::Sheet* titleSheet_ = nullptr;
    libxl::Sheet* processSheet_ = nullptr;
    libxl::Sheet* resultSheet_ = nullptr;

    int processRow_ = 0;
    int maxProcessCols_ = 10;

    libxl::Format* h1Fmt_ = nullptr;
    libxl::Format* h2Fmt_ = nullptr;
    libxl::Format* boldFmt_ = nullptr;
    libxl::Format* textFmt_ = nullptr;
    libxl::Format* tableHeaderFmt_ = nullptr;
    libxl::Format* numFmt_ = nullptr;
    libxl::Format* pivotRowColFmt_ = nullptr;
    libxl::Format* pivotElemFmt_ = nullptr;
    libxl::Format* resultFmt_ = nullptr;

    void setupFormats();
    static std::wstring formatLinearExpr(const std::vector<double>& coeffs);
};