#include "execute.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>

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

	/*
	 * TODO - handle the child in the parent.
	 * For a foreground command, call waitpid() for this specific child before
	 * returning. For a background command, do not wait here; return its PID so
	 * myshell.cpp can register it with the jobs module.
	 */
	ExecuteResult result = {true, params.getBackground() != 0, childPid};
	return result;
}
