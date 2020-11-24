#include "holberton.h"

/**
 *_strlen - function taht return the size of a string
 *@s: string
 *Return: size of string
 */
int _strlen(char *s)
{
	int size = 0;

	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

/**
 *_strcat - concatenate caracteres and strings
 *@dest: string to concatane
 *@src: string to add
 *Return: final string
 */
char *_strcat(char *dest, char *src)
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

/**
 *concat - concatenate the entier path of the command
 *@path_split: command to concatenate
 *Return: final string concatenate
 */
char *concat(char **path_split, char **cmd)
{
	int i = 0;
	int size = 0;
	char *result = NULL;
	struct stat st;

	while (path_split[i])
	{
		size = _strlen(path_split[i]) + _strlen(cmd[0]) + 2;
		path_split[i] = realloc(path_split[i], size);
		path_split[i] = _strcat(path_split[i], "/");
		path_split[i] = _strcat(path_split[i], cmd[0]);

		if (stat(path_split[i], &st) == 0)
		{
			result = _strdup(path_split[i]);
			free_array(path_split);
			return (result);
		}
		size = 0;
		i++;
	}
	return (NULL);
}

/**
 * get_path - get the entire path of command
 *@cmd: command
 *@ptrEnv: environement
 *Return: string of entire path
 */
char *get_path(char **cmd, list_t *ptrEnv)
{
	char *path = NULL;
	char *cat = NULL;
	char **path_split = NULL;
	char *ptr = NULL;
	char *result = NULL;
	struct stat st;
	int i = 0;

	if (_getenv("PATH", &ptrEnv) != NULL)
		path = _getenv("PATH", &ptrEnv);
	else
	{
		if (stat(cmd[0], &st) == 0)
		{
			result = _strdup(cmd[0]);
			return (result);
		}
		else
			return (NULL);
	}

	path_split = malloc(sizeof(char *) * 100);
	ptr = strtok(path, ":");
	while (ptr)
	{
		path_split[i] = _strdup(ptr);
		ptr = strtok(NULL, ":");
		i++;
	}
	path_split[i] = NULL;
	free(path);
	path = NULL;

	cat = concat(path_split, cmd);
	if (cat)
		result = cat;

	if (result == NULL && stat(cmd[0], &st) == 0)
		result = _strdup(cmd[0]);

	return (result);
}
