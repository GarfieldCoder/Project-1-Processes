#include "execute.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <cerrno>

ExecuteResult executeCommand(const Param &params) {
	ExecuteResult failure = {false, false, static_cast<pid_t>(-1)};

	/* An empty command has no program name to pass to execvp(). */
	if (params.getArgumentCount() == 0) {
		return failure;
	}

	pid_t childPid = fork();
	if (childPid < 0) {
		perror("myshell: fork");
		return failure;
	}

	if (childPid == 0) {
		const char *inputFile = params.getInputRedirect();
		if (inputFile != nullptr && freopen(inputFile, "r", stdin) == nullptr) {
			perror(inputFile);
			_exit(EXIT_FAILURE);
		}

		const char *outputFile = params.getOutputRedirect();
		if (outputFile != nullptr && freopen(outputFile, "w", stdout) == nullptr) {
			perror(outputFile);
			_exit(EXIT_FAILURE);
		}

		char *const *arguments = params.getArgumentVector();
		execvp(arguments[0], arguments);

		/* execvp() returns only when it cannot start the requested program. */
		perror(arguments[0]);
		_exit(127);
	}

	bool background = params.getBackground() != 0;

	/*
	* Foreground commands must finish before myshell displays another prompt.
	* Background commands return immediately so jobs.cpp can track their PID.
	*/
	if (!background) {
		pid_t waitResult;

		do {
			waitResult = waitpid(childPid, nullptr, 0);
		} while (waitResult == -1 && errno == EINTR); // A system call was interrupted by a signal before it finished.

		if (waitResult == -1) {
			perror("myshell: waitpid");
		}
	}

	/*
 	* We save whether the child started, whether it is running in the background,
 	* and its PID so myshell can decide if jobs.cpp, the home of background
	* process IDs, needs to keep track of it.
	*/
	ExecuteResult result = {
		true,
		params.getBackground() != 0,
		childPid
	};
	return result;
}
