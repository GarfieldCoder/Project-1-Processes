#ifndef EXECUTE_H
#define EXECUTE_H

#include <sys/types.h>

#include "param.hpp"

/*
 * Describes what happened when the shell tried to start a command.
 */
struct ExecuteResult {
	bool started;
	bool background;
	pid_t childPid;
};

/*
 * Starts the command stored in params and returns information
 * about whether the child process was created successfully.
 */
ExecuteResult executeCommand(const Param &params);

#endif
