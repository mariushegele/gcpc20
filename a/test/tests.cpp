#include <catch.hpp>
#include <fstream>
#include <vector>
#include <dirent.h>
#include "../include/BlockSolver.h"


TEST_CASE("positive tests", "[parse_pos]")
{
    SECTION("positive")
    {
        BlockSolver solver;
        string in;
        string exp;

        in = R""""(3
cube 7
cylinder 5
cube 11)"""";
        exp = R""""(cube 7
cylinder 5
cube 11
)"""";
        REQUIRE(solver.solve(in) == exp);
    }
    
    SECTION("2")
    {

        BlockSolver solver;
        string in;
        string exp;

        in = R""""(3
cube 4 
cylinder 2
cube 4)"""";
        exp = R""""(cylinder 2
cube 4
cube 4
)"""";

        REQUIRE(solver.solve(in) == exp);
    }

}

TEST_CASE("negative tests", "[parse_neg]")
{

    SECTION("negative")
    {
        BlockSolver solver;
        string in;
        string exp;

        in = R""""(2
cube 5 
cylinder 3)"""";
        exp = "impossible\n";
        REQUIRE(solver.solve(in) == exp);
    }
}

TEST_CASE("secret tests", "[test_secret]")
{
    SECTION("secret")
    {
        const string dirname = "test/secret";
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
            cout << endl;
        }
        sort(inputs.begin(), inputs.end());
        sort(answers.begin(), answers.end());

        for(unsigned long i=0; i<inputs.size(); i++) {
            cout << "inputs: " << inputs[i] << endl;
            cout << "answers: " << answers[i] << endl;

            ifstream input_fs;
            ifstream answer_fs;
            input_fs.open(dirname + "/" + inputs[i], ios::in);
            answer_fs.open(dirname + "/" + answers[i], ios::in);

            std::string input ( (std::istreambuf_iterator<char>(input_fs) ),
                                (std::istreambuf_iterator<char>()    ) );
            std::string answer( (std::istreambuf_iterator<char>(answer_fs) ),
                                (std::istreambuf_iterator<char>()    ) );
            
            cout << "input " << input << endl;

            string result = solver.solve(input);
            REQUIRE(result == answer);

            input_fs.close();
        }
    }
}
