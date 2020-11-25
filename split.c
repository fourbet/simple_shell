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

	s = malloc(sizeof(char) * _strlen(str) + 1);
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
	char separators[5] = " \r\n\t\f";
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
		if (_strncmp(_strdup(res), "#", 1) == 0)
		{
			break;
		}
		tab[i] = _strdup(res);
		res = strtok(NULL, separators);
		i++;
	}
	free(buffer);
	free(res);
	tab[i] = NULL;
	return (tab);
}
