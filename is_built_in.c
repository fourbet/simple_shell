#include "holberton.h"

int is_built_in(char *cmd)
{
	char *built_in[] = {"env", "exit", NULL};
	int i = 0;

	while (built_in[i])
	{
		if (_strcmp(built_in[i], cmd))
			return (1);
		i++;
	}

	return (0);
}
