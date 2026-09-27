#include "jobs.hpp"

#include <vector>
static std::vector<pid_t> backgroundPids; //Shared by all functions in file.

	/*
	* Background PID tracking:
	* Store childPid in a collection of active background process IDs.
	* Ignore invalid PIDs, and registering the same PID more than once.  
	*/
void registerBackgroundProcess(pid_t childPid) {
	if (childPid <= 0) {
        return;
    }

    for (pid_t storedPid : backgroundPids) {
        if (storedPid == childPid) {
            return;
        }
    }

    backgroundPids.push_back(childPid);
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
