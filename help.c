#include "holberton.h"
/**
 *built_in_help - display how to use a built in command
 *@cmd: command
 *Return: integer
 */
int built_in_help(char **cmd)
{
	int i = 0, j = 0;
char *built_n[] = {"env", "exit", "setenv", "unsetenv", "cd", "help", NULL};
char *built_i[] = {"Prints the current environnement\n",
			"Exits the shell\n",
	 "Initialize a new environnement variable or modify existing one\n",
	 "Remove an environnement variable\nFormat: unsetenv VARIABLE\n",
	 "Changes the current directory of the process\nFormat: cd DIRECTORY\n",
	 "Gives information about builtins\n Format: help BUILTIN\n",
	 NULL
};

	while (cmd[i] != NULL)
		i++;
	if (i == 1)
	{
		write(STDOUT_FILENO, "List of Built-ins :\n", 20);
		while (built_n[j] != NULL)
		{
			write(STDOUT_FILENO, built_n[j], _strlen(built_n[j]));
			write(STDOUT_FILENO, "\n", 1);
			j++;
		}
		return (1);
	}
	if (i > 2)
	{
		write(STDERR_FILENO, "Failure\n", 8);
		return (1);
	}
	i = 0;
	while (built_n[i] != NULL)
	{
		if (_strncmp(cmd[1], built_n[i], _strlen(built_n[i])) == 0)
		{
			write(STDOUT_FILENO, built_i[i], _strlen(built_i[i]));
			return (1);
		}
		i++;
	}
	return (1);
}
