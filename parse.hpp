#ifndef PARSE_HPP
#define PARSE_HPP

#include "param.hpp"

// Parses one writable, null-terminated command line into params.
void parseCommand(char *input, Param &params);

#endif
