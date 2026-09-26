#include <iostream>
#include <string>
#include "param.hpp"
#include "parse.hpp"
#include "execute.hpp"

int main(int argc, char* argv[]) {
	std::string buff;
	Param params;

	while(true) {
		//display prompt on stdout
		std::cout << ">>> ";

		//accept command string from user *check getline so eof also closes the shell
		if (!std::getline(std::cin, buff)) {
			break;
		}

		//terminate on exit command
		if(buff == "exit") {
			break;
		}

		//parse input into tokens and store in Param
		//pass params into parse *this will let the parser set redirects and background too
		parse(buff, params);

		//print contents when -Debug flag
		if(argc >= 2 && std::string(argv[1]) == "-Debug") {
			params.printParams();
		}

		executeCommand(params);
	}
	return 0;
}
