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

	if (s1 == NULL && s2 == NULL)
		return (-1);

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

/**
 * _strncmp - compares two stringds
 * @s1: pointer to a char
 * @s2: pointer to a char
 * @n: size
 *
 * Return: int
 */
int _strncmp(char *s1, char *s2, int n)
{
        int i = 0;
	int count = 0;
	
	if (s1 == NULL && s2 == NULL)
		return (-1);

        while (s1[i] != '\0' && s2[i] != '\0' && i < n)
        {
                if (s1[i] == s2[i])
                {
			count++;
                }
		else
			return (s1[i] - s2[i]);
                i++;
        }
	if (count == n)
		return (0);
	else
		return (-1);
}

int exec_builtin(char **cmd, list_t **ptrEnv)
{
	filt builtin[] = {{"env", built_in_env}, {"exit", built_in_exit},
			  {"setenv", built_in_setenv}, {"unsetenv", built_in_unsetenv},
			  {"cd", built_in_cd}, {NULL, NULL}};

	int i = 0;
	int res = 0;

	for (i = 0; builtin[i].id != NULL; i++)
	{
		if (_strcmp(cmd[0], builtin[i].id) == 0)
		{
			res = builtin[i].ptr_f(cmd, ptrEnv);
			return (res);
		}
	}
	return (-1);
}

