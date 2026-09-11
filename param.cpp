#include "param.hpp"

#include <cstring>
#include <iostream>

using namespace std;

// Make a private copy so Param owns every string stored in it.
char *copyString(const char *text) {
    int length;
    char *copy;

    length = strlen(text);
    copy = new char[length + 1];
    strcpy(copy, text);

    return copy;
}

Param::Param() {
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    background = 0;
    argumentCount = 0;

    for (int index = 0; index < MAXARGS; ++index) {
        argumentVector[index] = nullptr;
    }
}

Param::~Param() {
    reset();
}

void Param::reset() {
    delete[] inputRedirect;
    delete[] outputRedirect;
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    background = 0;

    for (int index = 0; index < argumentCount; ++index) {
        delete[] argumentVector[index];
        argumentVector[index] = nullptr;
    }
    argumentCount = 0;
}

void Param::setInputRedirect(const char *filename) {
    delete[] inputRedirect;
    inputRedirect = copyString(filename);
}

void Param::setOutputRedirect(const char *filename) {
    delete[] outputRedirect;
    outputRedirect = copyString(filename);
}

void Param::setBackground(int value) {
    background = value;
}

void Param::addArgument(const char *argument) {
    if (argumentCount < MAXARGS) {
        argumentVector[argumentCount] = copyString(argument);
        ++argumentCount;
    }
}

void Param::printParams() const {
    cout << "inputRedirect: ";
    if (inputRedirect == nullptr) {
        cout << "NULL";
    }
    else {
        cout << inputRedirect;
    }
    cout << endl;

    cout << "outputRedirect: ";
    if (outputRedirect == nullptr) {
        cout << "NULL";
    }
    else {
        cout << outputRedirect;
    }
    cout << endl;

    cout << "background: " << background << endl;
    cout << "argumentCount: " << argumentCount << endl;

    for (int index = 0; index < argumentCount; ++index) {
        cout << "argumentVector[" << index << "]: ";
        cout << argumentVector[index] << endl;
    }
}
