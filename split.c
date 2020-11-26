#include "holberton.h"

/**
 *free_array - free 2 dimension array
 *@tab: array
 *Return: void
 */
void free_array(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return;
	for (i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}

/**
 *nbr_words - return the number of words in a string
 *@s: string
 *@sep: separators
 *Return: integer
 */
int nbr_words(char *s, char *sep)
{
	int i = 1, j = 0;
	int nbw = 0;

	if (s == NULL)
		return (0);

	if (s[0] == '\n')
		return (1);

	if (*s != ' ')
		nbw++;

	while (s[i] != '\0')
	{
		j = 0;
		while (sep[j])
		{
			if (s[i - 1] == sep[j] && s[i] != sep[j])
				nbw++;
			j++;
		}
		i++;
	}
	free(sep);
	return (nbw);
}

/**
 *_strdup - duplicate a string
 *@str: string
 *Return: string duplicate
 */
char *_strdup(char *str)
{
	char *s = NULL;
	int i = 0;
	int size = 0;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	s = malloc(sizeof(char) * size);
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 *split - save array elements
 *@buffer: array
 *Return: 2 dimension array
 */
char **split(char *buffer)
{
	char *res = NULL;
	char **tab = NULL;
	char separators[6] = " \r\n\t\f";
	int count = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	count = nbr_words(buffer, _strdup(separators)) + 1;
	tab = malloc(sizeof(char *) * count);

	if (tab == NULL)
		return (0);

	buffer = _strdup(buffer);
	res = strtok(buffer, separators);

	while (res)
	{
		if (_strcmp(res, "#") == 0)
		{
			free(buffer);
			tab[i] = NULL;
			return (tab);
		}
		tab[i] = _strdup(res);
		res = strtok(NULL, separators);
		i++;
	}
	free(res);
	free(buffer);
	tab[i] = NULL;
	return (tab);
}
