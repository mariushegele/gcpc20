#include <iostream>
#include "math.h"

using namespace std;

class Solver
{
public:
    virtual ~Solver() = default;
    std::string solve(string);
};
