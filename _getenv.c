#include "holberton.h"

char *_strdelete(char *string)
{
        char *s;
        int i = 0;
        int j = 0;
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
        extern char **environ;
        char *env = NULL;
        char *res = NULL;
        int i = 0;
        int passed = 0;
        char **envPtr;
        char *string;
        list_t *current;

        current = *ptrEnv;

        while (current)
        {
                if ((strncmp(current->str, name, _strlen(name)) == 0))
                {
                        env = _strdelete(current->str);
                        passed = 1;
                        break;
                }
                current = current->next;
        }
        return (env);
}
