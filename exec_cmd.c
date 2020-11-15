#include "holberton.h"

void exec_cmd(char **cmd)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
		perror("error fork");

	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("error execve");
	}
	else
	{
		wait(&status);
		kill(child_pid, SIGTERM);
	}

	exit(EXIT_FAILURE);
}
