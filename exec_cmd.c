#include "holberton.h"

int exec_cmd(char **cmd, char *path)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
		perror("error fork");

	if (child_pid == 0)
	{
		if (execve(path, cmd, NULL) == -1)
		{
			perror("error execve");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		kill(child_pid, SIGTERM);
	}

	return (1);
}
