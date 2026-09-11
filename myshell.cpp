#include "param.hpp"
#include "parse.hpp"

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    bool debug;
    Param params;
    string command;
    char *input;

    debug = false;
    if (argc > 1) {
        if (strcmp(argv[1], "-Debug") == 0) {
            debug = true;
        }
    }

    while (true) {
        cout << "$$$ ";
        cout.flush();

        // getline reads the whole command, including spaces between words.
        if (!getline(cin, command)) {
            break;
        }

        if (command == "exit") {
            break;
        }

        // strtok needs a writable, null-terminated character array.
        input = new char[command.length() + 1];
        strcpy(input, command.c_str());
        parseCommand(input, params);
        delete[] input;

        if (debug) {
            params.printParams();
        }
    }

    return 0;
}
