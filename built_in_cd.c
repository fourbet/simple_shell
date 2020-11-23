#include "holberton.h"

int built_in_cd(char **cmd, list_t *env)
{
	char *path = NULL;
	list_t *current = NULL;
	char *ptr = NULL;
	char *cd = NULL;
	int ch = 1;

	current = env;
	cd = get_cd_path(cmd, env);
	if (cd)
	{
		puts("if");
		cmd[1] = cd;

		if (chdir(cmd[1]))
		{
			perror("chdir error");
			return (-1);
		}
		return (1);
	}
	else if (cmd[1] == NULL || _strcmp(cmd[1], "-") == 0)
	{
		puts("else if");
		while (current)
		{
			ptr = strtok(current->str, "=");
			path = _strdup(ptr);
			puts(path);
			if (_strcmp(path, "HOME") == 0)
			{
				puts("if strcmp");
				free(path);
				puts("test free");
				path = NULL;
				ptr = strtok(NULL, "\n");
				puts("test ptr");
				path = _strdup(ptr);
				puts(path);
				break ;
			}

			free(path);
			path = NULL;
			current = current->next;
		}
		puts(path);
		ch = chdir(path);
		if (ch < 0)
		{
			puts("if ch < 1");
			free(path);
			perror("chdir error");
			return (-1);
		}

		free(path);

		return (1);
	}

	return (-1);
}
