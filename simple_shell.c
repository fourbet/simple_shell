#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd;
	char *path;
	char *buffer = NULL;
	int bufsize = 1024;
	int read;

	buffer = malloc(sizeof(char) * bufsize);

	while (1)
	{
		type_prompt(env);

		if (getline(&buffer, &bufsize, stdin) == -1)
			perror("error getline");

		cmd = split(buffer);
		if (cmd == NULL)
			perror("error split");

		if (exec_builtin(cmd[0]) == -1)
			perror("error is built in");

		else if (get_path(cmd[0]) != NULL)
		{
			if (exec_cmd(cmd) == -1)
				perror("error exec cmd");
		}

		free(path);

		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}

	free(buffer);
	return (0);
}
