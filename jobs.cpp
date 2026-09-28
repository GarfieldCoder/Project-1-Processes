#include "jobs.hpp"
#include <sys/wait.h>
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
	//Start at the first PID in the vector.
    auto current = backgroundPids.begin();

    //Continue until every stored PID has been checked.
    while (current != backgroundPids.end()) {
        //WNOHANG checks the child without making myshell stop and wait.
        pid_t result = waitpid(*current, nullptr, WNOHANG);

        //A result of 0 means the child is still running.
        if (result == 0) {
            //Move to the next PID without removing this one.
            current++;
        }
        else {
            //The child finished, so remove its PID.
            //erase() returns the position of the next PID.
            current = backgroundPids.erase(current);
        }
    }
}

/* 
	 * Wait for every remaining background child before myshell exits,
	 * then clear the collection of background PIDs.
	 */ 
void waitForAllBackgroundProcesses() {
	//Visit every background PID that is still stored.
    for (pid_t childPid : backgroundPids) {
        //The 0 option makes myshell wait until this child finishes.
        waitpid(childPid, nullptr, 0);
    }

    //All background children are finished, so remove their stored PIDs.
    backgroundPids.clear();
}
