#include "holberton.h"

/**
 * env - function to execute builtin command env
 *
 *
 */

void built_in_env(list_t *env)
{
	while (env)
	{
		write(1, env->str, _strlen(env->str));
		putchar('\n');
		env = env->next;
	}
}
