#include "holberton.h"

/**
 *_strlen - function taht return the size of a string
 *@s: string
 *Return: size of string
 */
int _strlen(char *s)
{
	int size = 0;

	if (s == NULL)
		return (0);

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
	int i = 0;
	int j = 0;

	if (dest == NULL && src == NULL)
		return (NULL);

	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (dest);
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
 *@cmd: command
 *@st: struct stat
 *Return: final string concatenate
 */
char *concat(char **path_split, char **cmd, struct stat *st)
{
	int i = 0;
	int new_size = 0;
	int old_size = 0;
	char *result = NULL;

	while (path_split[i])
	{
		old_size = _strlen(path_split[i]);
		new_size = _strlen(path_split[i]) + _strlen(cmd[0]) + 2;
		path_split[i] = _realloc(path_split[i], old_size, new_size);
		path_split[i] = _strcat(path_split[i], "/");
		path_split[i] = _strcat(path_split[i], cmd[0]);

		if (stat(path_split[i], st) == 0)
		{
			result = _strdup(path_split[i]);
			free_array(path_split);
			return (result);
		}
		old_size = 0;
		new_size = 0;
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
	char *path = NULL, *cat = NULL, *ptr = NULL, *result = NULL;
	char **path_split = NULL;
	struct stat *st;
	int i = 0;

	st = malloc(sizeof(struct stat));
	path = _getenv("PATH=/", &ptrEnv);
	if (path == NULL)
	{
		if (stat(cmd[0], st) == 0)
		{
			result = _strdup(cmd[0]);
			free(st);
			return (result);
		}
		else
		{
			free(st);
			return (NULL);
		}
	}
	path_split = malloc(sizeof(char *) * 100);
	ptr = strtok(path, ":");
	while (ptr)
	{
		path_split[i] = _strdup(ptr);
		ptr = strtok(NULL, ":");
		i++;
	}
	free(ptr);
	path_split[i] = NULL;
	free(path);
	cat = concat(path_split, cmd, st);
	if (cat)
		result = cat;
	if (cat == NULL && stat(cmd[0], st) == 0)
		result = _strdup(cmd[0]);
	free(st);
	return (result);
}
