#include "param.hpp"
#include "parse.hpp"

#include <cstring>
#include <iostream>

using namespace std;

void runTest(int testNumber, const char *description, const char *command) {
    Param params;
    char input[200];

    strcpy(input, command);

    cout << "Test " << testNumber << ": " << description << endl;
    cout << "Input: " << command << endl;
    cout << "Program output:" << endl;

    parse(input, params);
    params.printParams();

    cout << endl;
}

int main() {
    cout << "Preliminary Testing" << endl;
    cout << "===================" << endl;
    cout << endl;

    // Test 1 checks a command containing only normal arguments.
    runTest(1, "Normal arguments", "one two three");
    cout << "Expected result: Three arguments, no redirects, and background 0."
         << endl;
    cout << "Pass belief: The test passes if the output matches that result."
         << endl;
    cout << endl;

    // Test 2 is the full example given in the project handout.
    runTest(2, "Redirects and background", "one two three <four >five &");
    cout << "Expected result: Three arguments, input four, output five, and "
         << "background 1." << endl;
    cout << "Pass belief: The test passes if the special tokens are not listed "
         << "as arguments." << endl;
    cout << endl;

    // Test 3 checks repeated spaces and tab characters.
    runTest(3, "Extra spaces and tabs", "cat     \ttestfile.txt");
    cout << "Expected result: Two arguments named cat and testfile.txt."
         << endl;
    cout << "Pass belief: The test passes if no empty arguments are created."
         << endl;
    cout << endl;

    // Test 4 checks input redirection without other special syntax.
    runTest(4, "Input redirect only", "cat <myshell.cpp");
    cout << "Expected result: One argument named cat and input myshell.cpp."
         << endl;
    cout << "Pass belief: The test passes if inputRedirect contains "
         << "myshell.cpp." << endl;

    return 0;
}
