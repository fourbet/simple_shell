#include "holberton.h"
/**
 *get_cd_path - find the path of directory
 *@cmd: command that we enter
 *@env: environnement
 *Return: string of path
 */
char *get_cd_path(char **cmd, list_t *env)
{
	char *path = NULL;

	if (cmd[1] == NULL || _strcmp(cmd[1], "-") == 0)
		return (NULL);

	path = malloc(sizeof(char) * 256);
	path = _getcwd(&env);

	if (path == NULL)
		return (NULL);

	return (path);
}
