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
		write(1, env->str, _strlen(env->str));
		putchar('\n');
		env = env->next;
	}
	return (1);
}
