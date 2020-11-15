#include "holberton.h"

/**
 * env - function to execute builtin command env
 *
 *
 */

int builtin_env(void)
{
	
	extern char** environ;

	int i = 0;

	if (environ == NULL)
		return (-1);
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
