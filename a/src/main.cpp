#include <cassert>
#include <iostream>
#include <../include/BlockSolver.h>
#include <fstream>

int main(int argc, char* argv[])
{
    BlockSolver solver;

    if(argc > 1) {
        cout << "Pass only filename as first argument" << endl;
        return 1;
    }
    char* filename = argv[0];
    std::ifstream ifs(filename);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    
    string output = solver.solve(content);
    cout << output << endl;
}
