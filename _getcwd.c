#include "holberton.h"
/**
 * _getcwd - get current working directory
 *
 * @env: list_t
 *
 * Return: path
 */
char *_getcwd(list_t **env)
{
	char *cwd = NULL;
	char *ptr = NULL;
	list_t *current = NULL;

	current = *env;
	while (current)
	{
		ptr = strtok(current->str, "=");
		cwd = _strdup(ptr);
		if (_strcmp(cwd, "PWD") == 0)
		{
			free(cwd);
			cwd = NULL;
			ptr = strtok(NULL, "\n");
			cwd = _strdup(ptr);
			break;
		}

		current = current->next;
	}

	return (cwd);
}
