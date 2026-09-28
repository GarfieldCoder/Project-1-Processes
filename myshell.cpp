#include <iostream>
#include <string>
#include "param.hpp"
#include "parse.hpp"
#include "execute.hpp"
#include "jobs.hpp"

int main(int argc, char* argv[]) {
	std::string buff;
	Param params;

	while(true) {
		// COLLECT ANY BACKGROUND PROCESSES THAT HAVE FINISHED
		reapBackgroundProcesses(); 

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
		

		ExecuteResult result = executeCommand(params); //Returns started, background, and childPid, to pass background PIDs to jobs :P

		//Track the child PID only when a background process started successfully.
		if (result.started && result.background) {
			registerBackgroundProcess(result.childPid);
		}

	}

	waitForAllBackgroundProcesses(); //handle possible shutdown paths 
	return 0;
}
