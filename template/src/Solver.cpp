#include <iostream>
#include <sstream>

#include "../include/Solver.h"

using namespace std;

string Solver::solve(string input)
{
    std::string result;

    std::istringstream f(input);
    std::string line; 
    uint i=0;
    while (std::getline(f, line)) {
        i++;
    }

    return result;
};