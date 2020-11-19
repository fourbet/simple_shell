#include "holberton.h"

void free_array(char **tab)
{
	int i = 0;

	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int nbr_words(char *s)
{
	int i = 1;
	int nbw = 0;

	if (s == NULL)
		return (0);

	if (*s != ' ')
		nbw++;

	while (s[i] != '\0')
	{
		if (s[i - 1] == ' ' && s[i] != ' ')
			nbw++;
		i++;
	}
	return (nbw);
}

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

char **split(char *buffer)
{
	char *res = NULL;
	char **tab = NULL;
	int count = 0;
	int i = 0;

	count = nbr_words(buffer) + 1;
	tab = malloc(sizeof(char *) * count);

	if (tab == NULL)
		return (0);

	res = strtok(buffer, " \n");
	while (res)
	{
		tab[i] = strdup(res);
		res = strtok(NULL, " \n");
		i++;
	}

	tab[i] = NULL;
	return (tab);
}
