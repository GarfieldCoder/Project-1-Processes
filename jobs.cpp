#include "jobs.hpp"

void registerBackgroundProcess(pid_t childPid) {
	/*
	 * TODO Part II - background PID tracking:
	 * Store childPid in a collection of active background process IDs. Ignore
	 * invalid PIDs, and avoid registering the same PID more than once.
	 */
	(void)childPid;
}

void reapBackgroundProcesses() {
	/*
	 * TODO Part II - prevent zombie processes while the shell is running:
	 * Check the stored background PIDs with waitpid() and WNOHANG. Remove each
	 * PID whose child has finished. Do not block while a child is still active.
	 * This function should be called regularly, such as before each prompt.
	 */
}

void waitForAllBackgroundProcesses() {
	/*
	 * TODO Part II - clean shutdown:
	 * When the user enters exit or input reaches EOF, call waitpid() for every
	 * background PID that is still stored. Do not let myshell terminate until
	 * all of its background children have finished, then clear the collection.
	 */
}
