#include "holberton.h"
/**
 *built_in_help - display how to use a built in command
 *@cmd: command
 *Return: integer
 */
int built_in_help(char **cmd)
{
	int i = 0;
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

	if (i != 2)
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
	write(STDERR_FILENO, "Failure\n", 8);
	return (1);
}
