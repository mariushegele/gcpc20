#include <iostream>
#include "math.h"

using namespace std;

class BlockSolver
{
public:
    virtual ~BlockSolver() = default;
    std::string solve(string);
};
