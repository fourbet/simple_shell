#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strlen(char *s)
{
	int size = 0;

	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}
char*_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

char *get_path(char **cmd)
{
	char *path = strdup(getenv("PATH"));
	char **path_split = malloc(sizeof(char *) * 64);
	char *ptr;
	char *result = NULL;
	struct stat st;
	int i = 0;

 	ptr = strtok(path, ":");
	while (ptr)
	{
		path_split[i] = strdup(ptr);
		puts(ptr);
		ptr = strtok(NULL, ":");
		i++;
	}

	path_split[i] = NULL;
	free(path);
	path = NULL;

	i = 0;
	while (path_split[i])
	{
		path_split[i] = realloc(path_split[i], _strlen(path_split[i]) + _strlen(cmd[0]) + 2);
		path_split[i] = strcat(path_split[i], "/");
		path_split[i] = strcat(path_split[i], cmd[0]);

		if (stat(path_split[i], &st) == 0)
			break ;

		i++;
	}

	result = strdup(path_split[i]);
	i = 0;
	while (path_split[i])
	{
		free(path_split[i++]);
	}
	free(path_split);

	return (result);
}

int main(void)
{
	char *cmd[] = {"pwd", NULL};
	char * result = NULL;

	result = get_path(cmd);
	printf("result : %s\n", result);

	free(result);
	return (0);
}
