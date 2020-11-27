#include "holberton.h"
/**
 * built_in_exit - function to execute builtin command exit
 *@cmd: command that we enter to the shell
 *@ptrEnv: list_t *
 *Return: 1 for failure and 0 for success
 */
int built_in_exit(char **cmd, list_t *ptrEnv)
{
	int status;
	int i = 0;

	while (cmd[i] != NULL)
	{
		i++;
	}

	if (i == 1)
		return (0);
	if (i == 2)
	{
		if (cmd[1][0] >= 65 && cmd[1][0] <= 122)
		{
			return (99);
		}
		else if (_atoi(cmd[1]) >= 0)
		{
			status = _atoi(cmd[1]);
			free_list(ptrEnv);
			free_array(cmd);
			exit(status);
		}
		else
		{
			return (99);
		}

	}
	else
	{
		write(STDERR_FILENO, "Failure\n", 8);
		return (1);
	}

}
