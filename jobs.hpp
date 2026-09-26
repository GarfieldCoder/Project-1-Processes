#ifndef JOBS_H
#define JOBS_H

#include <sys/types.h>

/* Remember a child that was started as a background process. */
void registerBackgroundProcess(pid_t childPid);

/* Reap background children that have already finished without blocking. */
void reapBackgroundProcesses();

/* Wait for every remaining background child before myshell exits. */
void waitForAllBackgroundProcesses();

#endif
