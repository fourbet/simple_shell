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
 *@str: string
 *@sep: separators
 *Return: integer
 */
int nbr_words(char *str, char *sep)
{
	int i = 0, j = 0, count = 0;

	while (str[i] != '\0')
	{
		while (sep[j] != '\0')
		{
			if (str[i] == sep[j])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

/**
 *print_array - print a 2 dimension array
 *@tab: array
 *Return: void
 */
void print_array(char **tab)
{
	int i = 0;

	for (i = 0; tab[i]; i++)
	{
		printf("tab[%d] :%s\n", i, tab[i]);
	}
}

/**
 *_strdup - duplicate a string
 *@str: string
 *Return: string duplicate
 */
char *_strdup(char *str)
{
	char *s;
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
	char separators[3] = " \n\t";
	int count = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	count = nbr_words(buffer, separators);
	tab = malloc(sizeof(char *) * (count + 1));

	if (tab == NULL)
		return (0);
	buffer = _strdup(buffer);

	res = strtok(buffer, separators);
	while (res)
	{
		tab[i] = strdup(res);
		res = strtok(NULL, separators);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
