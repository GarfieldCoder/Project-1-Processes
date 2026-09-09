#include "param.hpp"

#include <iostream>

Param::Param()
    : inputRedirect(nullptr),
      outputRedirect(nullptr),
      background(0),
      argumentCount(0) {
    for (int index = 0; index < MAXARGS; ++index) {
        argumentVector[index] = nullptr;
    }
}

Param::~Param() {
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
