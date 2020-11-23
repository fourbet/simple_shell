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

	if (_strlen(s1) == _strlen(s2))
	{
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
	}
	else
		return (-1);

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

int is_built_in(char *cmd)
{
        char *built_in[] = {"env", "exit", "setenv", "unsetenv", "cd", "help", NULL};
        int i = 0;

        while (built_in[i])
        {
                if (_strcmp(built_in[i], cmd) == 0)
                        return (0);
                i++;
        }

        return (1);
}

int exec_built_in(char **cmd, list_t *env)
{
	int res = 0;

        if (_strcmp(cmd[0], "env") == 0)
                res = built_in_env(env);

        if (_strcmp(cmd[0], "exit") == 0)
                res = built_in_exit(cmd);

        if (_strcmp(cmd[0], "setenv") == 0)
                res = built_in_setenv(cmd, &env);

        if (_strcmp(cmd[0], "unsetenv") == 0)
                res = built_in_unsetenv(cmd, &env);

        if (_strcmp(cmd[0], "cd") == 0)
                 res = built_in_cd(cmd, env);

	if (_strcmp(cmd[0], "help") == 0)
		res = built_in_help(cmd);

        return (res);
}
