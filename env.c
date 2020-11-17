#include "holberton.h"

/**
 * env - function to execute builtin command env
 *
 *
 */

void built_in_env(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		putchar('\n');
		i++;
	}
}
