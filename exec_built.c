#include "holberton.h"

int _strcmp(const char *init, char *other)
{
        int i = 0;

        if (strcmp(init, other) != 0)
                return (0);

        else
        {
                while (init[i] && init)
                {
                        if (init[i] != other[i])
                                return (0);
                        else
                                i++;
                }
        }
        return (1);
}

int exec_built(char **cmd)
{
	if (_strcmp(cmd[0], "env"))
	{
		built_in_env();
		return (1);
	}

	if (_strcmp(cmd[0], "exit"))
	{
		return (0);
	}

	return (1);
}
