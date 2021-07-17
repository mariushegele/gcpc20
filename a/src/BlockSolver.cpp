#include <iostream>
#include "../include/BlockSolver.h"
#include <sstream>

using namespace std;

/*
type a <= 1000

cube side length => A = a*a
cylinder r       => A = r^2 * pi
*/

struct Block {
    string type;
    uint size;
};

bool compareBlocks(Block b1, Block b2)
{
    if(b1.type == b2.type) {
        return b1.size < b2.size;
    } else {
        if(b1.type == "cylinder") {                
            if(2*b1.size < b2.size) {
                return true;
            } else if(2*b1.size > b2.size) {
                return false;
            } else {
                return true;
            }
        } else {
            if(b1.size < 2*b2.size) {
                return true;
            } else if(b1.size > 2*b2.size) {
                return false;
            } else {
                return false;
            }
        }
    }
}

string BlockSolver::solve(string input)
{
    Block blocks[100];
    std::string result;

    std::istringstream f(input);
    std::string line; 
    uint i=0;
    uint n=0;
    while (std::getline(f, line)) {
        if(i==0) {
            n=stoul(line); 
        } else {
            string c = line.substr(0,line.find(' '));
            string s = line.substr(line.find(' ')+1);

            blocks[i-1].type = c;
            blocks[i-1].size = stoul(s);
        }
        i++;
    }

    sort(blocks, blocks + n, compareBlocks);
 
    for (uint i = 0; i < n; i++) {

        if(i != 0) {
            if(blocks[i].type == "cylinder"
                && blocks[i-1].type == "cube"
                && sqrt(2)*blocks[i].size < blocks[i-1].size) 
            {
                return "impossible\n";
            }
        }
        result += blocks[i].type + ' ' + to_string(blocks[i].size) + '\n';
    }

    return result;
};
