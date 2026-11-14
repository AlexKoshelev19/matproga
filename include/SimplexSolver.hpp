#pragma once

#include "LPModels.hpp"
#include "ExcelReporter.hpp"
#include <vector>
#include <string>

class SimplexSolver
{
public:
    explicit SimplexSolver(const LPProblem& problem);

    SolveStatus solve(ExcelReporter& reporter);

    const std::vector<double>& getSolution() const { return solution_; }
    double getObjectiveValue() const { return objectiveValue_; }
    const std::wstring& getStatusMessage() const { return statusMessage_; }

private:
    LPProblem problem_;
    std::vector<std::vector<double>> matrix_;
    std::vector<int> basis_;
    std::vector<int> artificials_;

    int n_original_ = 0;
    int n_total_ = 0;

    std::vector<double> solution_;
    double objectiveValue_ = 0.0;
    std::wstring statusMessage_;

    void buildCanonicalTableau();
    void updateObjectiveRow(const std::vector<double>& coeffs);
    void pivot(int pivot_row, int pivot_col);

    int findEnteringColumn(bool maximize_obj) const;
    int findLeavingRow(int pivot_col, double& min_ratio) const;

    SolveStatus runSimplexIterations(bool maximize_obj,
                                     const std::wstring& phase_name,
                                     ExcelReporter& reporter);

    bool removeArtificialBasis(ExcelReporter& reporter);
    void removeArtificialColumns();
    void extractOptimalSolution();
    void printMatrixConsole() const;
};