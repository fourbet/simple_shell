#include "holberton.h"
/**
 * built_in_exit - function to execute builtin command exit
 *@cmd: command that we enter to the shell
 *Return: 1 for failure and 0 for success
 */
int built_in_exit(char **cmd)
{
	int status;
	int i = 0;

	while (cmd[i] != NULL)
		i++;

	if (i == 1)
		return (0);
	if (i == 2)
	{
		status = _atoi(cmd[1]);
		exit(status);
	}
	else
	{
		write(STDERR_FILENO, "Failure\n", 8);
		return (1);
	}

}
