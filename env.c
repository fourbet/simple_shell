#include "holberton.h"

/**
 * built_in_env - prints the environnement variables
 * @env: list of environnement variables
 *
 * Return: 1(SUCESS), -1(FAILURE)
 */
int built_in_env(list_t *env)
{
	if (env == NULL)
		return (-1);

	while (env)
	{
		write(STDOUT_FILENO, env->str, _strlen(env->str));
		write(STDOUT_FILENO, "\n", 1);
		env = env->next;
	}
	return (1);
}
