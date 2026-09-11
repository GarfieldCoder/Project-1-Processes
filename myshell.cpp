#include <iostream>
#include <string>
#include "param.hpp"
#include "parse.hpp"

int main(int argc, char* argv[]) {
	std::string buff;
	while(true) {
		//display prompt on stdout
		std::cout << ">>> ";
		
		//accept command string from user
		std::getline(std::cin, buff);
		
		//terminate on exit command
		if(buff == "exit") {
			break;
		}
		
		//parse input into tokens and store in Param
		Param params = parse(buff);
		
		//print contents when -Debug flag
		if(argc >= 2 && std::string(argv[1]) == "-Debug") {
			params.printParams();
		}
		std::cout << buff << std::endl;
	}
	return 0;
}