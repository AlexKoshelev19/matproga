#pragma once

#include "LPModels.hpp"
#include <string>

class InputReader
{
public:
    static bool readFromFile(const std::string& filename, LPProblem& problem);
    static bool readFromConsole(LPProblem& problem);
};