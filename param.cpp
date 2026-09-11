#include "param.hpp"

#include <cstring>
#include <iostream>

//copy the text so Param does not depend on the parser's temporary buffer
char *copyString(const char *text) {
	int length;
	char *copy;

	length = strlen(text);
	copy = new char[length + 1];
	strcpy(copy, text);

	return copy;
}

Param::Param()
    : inputRedirect(nullptr),
      outputRedirect(nullptr),
      background(0),
      argumentCount(0) {
    for (int index = 0; index < MAXARGS; ++index) {
        argumentVector[index] = nullptr;
    }
}

Param::Param(int argc, char* argv[])
    : inputRedirect(nullptr),
      outputRedirect(nullptr),
      background(0),
      argumentCount(argc) {
	//limit the count *the array only has MAXARGS spaces
	if (argumentCount > MAXARGS) {
		argumentCount = MAXARGS;
	}

	for (int i=0; i<MAXARGS; ++i) {
		if (i < argumentCount) {
			//copy the argument bcoz the original pointer only lived as long as the parser buffer
			argumentVector[i] = copyString(argv[i]);
		} else {
			argumentVector[i] = nullptr;
		}
	}
}


Param::~Param() {
	reset();
}

void Param::reset() { //memory leak :'(
	delete[] inputRedirect;
	delete[] outputRedirect;
	inputRedirect = nullptr;
	outputRedirect = nullptr;
	background = 0;

	for (int index = 0; index < argumentCount; index++) {
		delete[] argumentVector[index];
		argumentVector[index] = nullptr;
	}

	argumentCount = 0;
} //memory is happy

//added setters and getters for Param class
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
		argumentCount++;
	}
}

void Param::printParams() const {
    std::cout << "inputRedirect: "
              << (inputRedirect == nullptr ? "NULL" : inputRedirect) << '\n';
    std::cout << "outputRedirect: "
              << (outputRedirect == nullptr ? "NULL" : outputRedirect) << '\n';
    std::cout << "background: " << background << '\n';
    std::cout << "argumentCount: " << argumentCount << '\n';

    for (int index = 0; index < argumentCount; ++index) {
        std::cout << "argumentVector[" << index << "]: "
                  << argumentVector[index] << '\n';
    }
}
