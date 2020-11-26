#include "holberton.h"
/**
 * exec_cmd - execute command in the PATH
 * @cmd: list of commands
 *
 * Return: 1(SUCESS), -1(FAILURE)
 */
int exec_cmd(char **cmd)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
		perror("fork");

	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execve");
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
