#pragma once

#include <vector>
#include <string>

constexpr double EPS = 1e-9;

enum class SolveStatus
{
    Optimal,
    Unbounded,
    Infeasible,
    Error
};

struct Constraint
{
    std::vector<double> a;
    std::string sign;
    double b = 0.0;
};

struct LPProblem
{
    int n = 0;
    int m = 0;
    bool maximize = true;
    std::vector<double> objective;
    std::vector<Constraint> constraints;
};