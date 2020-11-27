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
 *@src: source file
 *@dest: destination file
 *@delim: delimiter
 *Return: final string concatenate
 */
char *concat(char *src, char *dest, char delim)
{
	char *concat;
	int len;
	int i = 0;
	int j = 0;

	len = _strlen(src) + _strlen(dest) + 2;
	concat = malloc(sizeof(char) * len);
	if (concat == 0)
		return (0);

	for (i = 0; src[i]; i++)
		concat[i] = src[i];
	concat[i] = delim;
	i++;
	for (j = 0; dest[j]; j++)
	{
		concat[i] = dest[j];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}

/**
 * get_path - get the entire path of command
 *@cmd: command
 *@ptrEnv: environement
 *Return: string of entire path
 */
char *get_path(char **cmd, list_t *ptrEnv)
{
	char *path = NULL, *tmp = NULL, *ptr = NULL, *result = NULL;
	struct stat *st;
	int i = 0;

	st = malloc(sizeof(struct stat));
	path = _getenv("PATH=/", &ptrEnv);
	if (path == NULL)
	{
		if (stat(cmd[0], st) == 0)
		{
			result = cmd[0];
			free(path);
			free(st);
			return (result);
		}
		else
		{			free(st);
			free(path);
			return (NULL);
		}
	}
	ptr = strtok(path, ":");
	while (ptr)
	{
		tmp = concat(ptr, cmd[0], '/');
		i = stat(tmp, st);
		if (i == 0)
		{
			free(st);
			free(path);
			free(cmd[0]);
			return (tmp);
		}
		ptr = strtok(NULL, ":");
		free(tmp);
		i++;
	}
	free(path);
	free(st);
	return (cmd[0]);
}
