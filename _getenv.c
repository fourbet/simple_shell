#include "holberton.h"

char *_strdelete(char *string)
{
        char *s;
        int i = 0;
	int index = 0;
        s = malloc(sizeof(char) * _strlen(string));
	while(string[i] != '\0')
	{
		if (string[i] == '=')
		{
			index = i;
			break;
		}
		i++;
	}
	i = 0;
	index++;
	while (string[index] != '\0')
	{
		s[i] = string[index];
		index++;
		i++;
	}
        return (s);
}

char *_getenv(char *name, list_t **ptrEnv)
{
	char *env = NULL;
	list_t *current;

        current = *ptrEnv;

        while (current)
        {
                if ((strncmp(current->str, name, _strlen(name)) == 0))
                {
                        env = _strdelete(current->str);
                        break;
                }
                current = current->next;
        }
        return (env);
}
