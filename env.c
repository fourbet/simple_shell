#include "holberton.h"

/**
 * env - function to execute builtin command env
 *
 *
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
