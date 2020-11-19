#include "holberton.h"

void free_array(char **tab)
{
	int i = 0;
	if (tab == NULL)
		return;
	for(i = 0; tab[i]; i++)
	{
		free(tab[i]);
	}
	free(tab);
}
int nbr_words(char *str, char *sep)
{
	int i = 0, j = 0, count = 0;

        while (str[i] != '\0')
        {
                while(sep[j] != '\0')
                {
                        if (str[i] == sep[j])
                                count++;
                        j++;
                }
                j = 0;
                i++;
        }
	return (count + 1);
}

void print_array(char **tab)
{
	int i = 0;

	for (i = 0; tab[i] ; i++)
        {
                printf("tab[%d] :%s\n",i, tab[i]);
        }
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
	char separators[2] = " \n";
	char *res = NULL;
	char **tab = NULL;
	int count = 0;
	int k = 0;

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
		tab[k] = _strdup(res);
		res = strtok(NULL, separators );
		k++;
	}
	tab[k] = NULL;
	free(buffer);

	return (tab);
}
