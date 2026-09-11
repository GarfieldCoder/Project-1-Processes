#include "parse.hpp"
#include <cstring>
#include <cstdlib>
#include <iostream>

void parse(std::string input, Param &params) {
	params.reset();

	//duplicate string as char array so it can be tokenized
	char *buffer = strdup(input.c_str());

	char *token = strtok(buffer, " \t\n");
	while (token != nullptr) {
		if (token[0] == '<' && token[1] != '\0') {
			params.setInputRedirect(token + 1);
		}
		else if (token[0] == '>' && token[1] != '\0') {
			params.setOutputRedirect(token + 1);
		}
		else if (strcmp(token, "&") == 0) {
			params.setBackground(1);
		}
		else if (strcmp(token, "<") == 0 || strcmp(token, ">") == 0) {
			//check missing redirect filename *this parser expects <file or >file
			std::cerr << "Error: a redirect must include a filename.";
			std::cerr << std::endl;
		}
		else {
			params.addArgument(token);
		}

		token = strtok(nullptr, " \t\n");
	}

	//free the buffer *Param owns copies of the strings now
	free(buffer);
}
