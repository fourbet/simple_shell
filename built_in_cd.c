#include "holberton.h"

int built_in_cd(char **cmd, list_t **env)
{
	int i = 0;
	char *home = NULL;
	char *path = NULL;
	char **new = NULL;
	list_t *current;
	char *ptr;

	current = *env;
	new = malloc(sizeof(char *) * 2);
	new[0] = _strdup(cmd[1]);
	new[1] = NULL;

	while (cmd[i])
		i++;
	if (i > 2)
		return (-1);

	if (get_path(new, *env))
	{
		cmd[1] = get_path(new, *env);
		if (chdir(cmd[1]) != 0)
		{
			perror("error chdir");
			return (-1);
		}
	}
	else if ((_strcmp(cmd[1], "-") == 0) || cmd[1] == NULL)
	{
		while (current)
		{
			if (_strcmp(current->str, home))
				break ;
			current = current->next;
		}

		ptr = strtok(current->str, "=");
		ptr = strtok(NULL, "\n");

		path = strdup(ptr);
		chdir(path);
	}
	else
		return (-1);

	return (1);
}
