#include "holberton.h"

int _strlen(char *s)
{
	int size = 0;

	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char*_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
		if (src[j] == '\0')
		{
			dest[i] = '\0';
		}
	}
	return (dest);
}

char *get_path(char **cmd, list_t *ptrEnv)
{
	/*char *path = strdup(_getenv("PATH", &ptrEnv));*/
	char *path;
	char **path_split = malloc(sizeof(char *) * 64);
	char *ptr;
	char *result = NULL;
	struct stat st;
	int i = 0;

	if (_getenv("PATH", &ptrEnv) != NULL)
		path = (_getenv("PATH", &ptrEnv));

 	ptr = strtok(path, ":");
	while (ptr)
	{
		path_split[i] = strdup(ptr);
		ptr = strtok(NULL, ":");
		i++;
	}

	path_split[i] = NULL;
	free(path);
	path = NULL;

	i = 0;
	while (path_split[i])
	{
		path_split[i] = realloc(path_split[i], _strlen(path_split[i]) + _strlen(cmd[0]) + 2);
		path_split[i] = strcat(path_split[i], "/");
		path_split[i] = strcat(path_split[i], cmd[0]);

		if (stat(path_split[i], &st) == 0)
			break ;

		i++;
	}

	if (path_split[i])
		result = strdup(path_split[i]);

	if (result == NULL && stat(cmd[0], &st) == 0)
		result = cmd[0];	    

	i = 0;
	while (path_split[i])
	{
		free(path_split[i++]);
	}
	free(path_split);

	return (result);
}
