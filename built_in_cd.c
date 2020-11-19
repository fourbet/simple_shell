#include "holberton.h"

int built_in_cd(char **cmd, list_t **env)
{
	int i = 0;
	char *home = NULL;
	char *path = NULL;

	while (cmd[i])
		i++;
	if (i > 2)
		return (-1);

	if (get_path(cmd[1]))
	{
		cmd[1] = get_path(cmd[1]);
		if (chdir(cmd[1]) != 0)
		{
			perror("error chdir");
			return (-1);
		}
	}
	else if (cmd[1] == '-' || cmd[1] == NULL)
	{
		while (*env->next)
		{
			if (_strcmp(*env->str, home))
				break ;
			*env = *env->next;
		}

		ptr = strtok(*env->next, "=");
		ptr = strtok(NULL, "\n");

		path = strdup(ptr);
		chdir(path);
	}
	else
		return (-1);

	return (1);
}
