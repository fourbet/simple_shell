#include "holberton.h"

/**
 * env - function to execute builtin command env
 *
 *
 */

int built_in_env(char **cmd, list_t **ptrEnv)
{
	list_t *tmp = *ptrEnv;

	while (tmp != NULL)
        {
                if (tmp->str != NULL)
                        printf("%s\n", tmp->str);
                else
                        printf("(nil)\n");
                tmp = tmp->next;
        }
	return (1);
}
