#include "parse.hpp"
#include <cstring>

Param parse(std::string input) {
	char *argv[MAXARGS];
	int argc = 0;
	
	//duplicate string as char array so it can be tokenized
	char *buffer = strdup(input.c_str());
	
	char *token = strtok(buffer, " \t\n");
	while (token != nullptr && argc < MAXARGS-1) {
		argv[argc] = token;
		argc++;
		token = strtok(nullptr, " \t\n");
	}
	argv[argc] = nullptr;
	
	Param params(argc, argv);
	return params;
};