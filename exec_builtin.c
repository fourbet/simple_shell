#include "holberton.h"
/**
 * _strcmp - compares two stringds
 * @s1: pointer to a char
 * @s2: pointer to a char
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int exec_builtin(char *cmd)
{
	filt builtin[] = {{"env", built_in_env}, {"exit", built_in_exit},/*
			  {"setenv", builtin_setenv}, {"unsetenv", builtin_unsetenv},
			  {"cd", builtin_cd},*/ {NULL, NULL}};

	int i = 0;
	int res = 0;

	for (i = 0; builtin[i].id != NULL; i++)
	{
		if (_strcmp(cmd, builtin[i].id) == 0)
		{
			res = builtin[i].ptr_f();
			return (res);
		}
	}
	return (-1);
}
