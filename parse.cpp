#include "parse.hpp"

#include <cstring>
#include <iostream>

using namespace std;

void parseCommand(char *input, Param &params) {
    char *token;

    params.reset();

    // strtok treats any run of spaces, tabs, and newlines as a delimiter.
    token = strtok(input, " \t\n");
    while (token != nullptr) {
        if (token[0] == '<' && token[1] != '\0') {
            params.setInputRedirect(token + 1);
        }
        else if (token[0] == '>' && token[1] != '\0') {
            params.setOutputRedirect(token + 1);
        }
        else if (strcmp(token, "<") == 0) {
            // This parser requires the filename to touch the redirect symbol.
            cerr << "Error: a redirect must include a filename." << endl;
        }
        else if (strcmp(token, ">") == 0) {
            // This parser requires the filename to touch the redirect symbol.
            cerr << "Error: a redirect must include a filename." << endl;
        }
        else if (strcmp(token, "&") == 0) {
            params.setBackground(1);
        }
        else {
            params.addArgument(token);
        }

        token = strtok(nullptr, " \t\n");
    }
}
