#include "holberton.h"

char *_getenv(const char *name)
{
	extern char **environ;
        char *env = NULL;
	char *res = NULL;
	int i = 0;
	char **envPtr;

	envPtr = malloc(sizeof(char *) * 32);
	
	while(environ[i])
	{
		envPtr[i] = strdup(environ[i]);
		i++;
	}
	envPtr[i] = NULL;
	i = 0;
	while (envPtr[i] != NULL)
	{
		res = strtok(envPtr[i], "=\n");
		if ((strcmp(res, name) == 0))
		{
			res = strtok(NULL, "=\n");
			break;
		}
		i++;
	}
	env = strdup(res);
	i = 0;
	while (envPtr && envPtr[i])
	{
		free(envPtr[i]);
		i++;
	}
	free(envPtr);
        return (env);
}

