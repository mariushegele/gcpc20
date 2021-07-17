#include <catch.hpp>
#include <fstream>
#include <vector>
#include <dirent.h>
#include "../include/BlockSolver.h"

void test_all_in(const string dirname)
{
        BlockSolver solver;
        vector<string> inputs;
        vector<string> answers;
        
        dirent *dirp;
        DIR * dir = opendir(dirname.c_str());
        while ((dirp = readdir(dir)) != NULL) {
            std::string fname = dirp->d_name;
            if(fname == "." || fname == "..") {
                // do nothing
            } else if(fname.find(".in") != std::string::npos) {
                inputs.push_back(fname);
            } else {
                answers.push_back(fname);
            }
        }
        sort(inputs.begin(), inputs.end());
        sort(answers.begin(), answers.end());

        for(unsigned long i=0; i<inputs.size(); i++) {
            ifstream input_fs;
            ifstream answer_fs;
            input_fs.open(dirname + "/" + inputs[i], ios::in);
            answer_fs.open(dirname + "/" + answers[i], ios::in);

            std::string input ( (std::istreambuf_iterator<char>(input_fs) ),
                                (std::istreambuf_iterator<char>()    ) );
            std::string answer( (std::istreambuf_iterator<char>(answer_fs) ),
                                (std::istreambuf_iterator<char>()    ) );
            
            string result = solver.solve(input);
            REQUIRE(result == answer);

            input_fs.close();
        }
}

TEST_CASE("tests")
{
    SECTION("sample")
    {
        test_all_in("test/sample");
    }

    SECTION("secret")
    {
        test_all_in("test/secret");
    }
}
