#include "holberton.h"

char *get_cd_path(char **cmd, list_t *env)
{
	char *path = NULL;

	if (cmd[1] == NULL || _strcmp(cmd[1], "-") == 0)
		return (NULL);

	path = malloc(sizeof(char) * 256);
	printf("cmd[1] : %s\n", cmd[1]);
	path = _getcwd(&env);
	printf("getcwd : %s\n", path);
	if (path == NULL)
		return (NULL);

/*	path = strcat(path, "/");
	path = strcat(path, cmd[1]);
*/
	printf("path : %s\n", path);
	return (path);
}
