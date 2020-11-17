#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *path;
	char *buffer = NULL;
	size_t bufsize = 1024;
	int i = 0;
	int built = 0;

	buffer = malloc(sizeof(char) * bufsize);

	while (1)
	{
		type_prompt(env);

		if (!getline(&buffer, &bufsize, stdin) > 0)
			perror("error getline");

		cmd = split(buffer);

		if (cmd == NULL)
		{
			perror("error split");
			return (-1);
		}

		built = exec_built(cmd);
		if (built == 0)
			return (0);
		if (built == -1)
		{
			perror("error is built in");
			return (-1);
		}

		path = get_path(cmd);

		if (path == NULL)
                {
			i = 0;
                        while (cmd[i])
                        {
                                write(1, cmd[i], _strlen(cmd[i]));
                                putchar(' ');
                                i++;
                        }
                        write(1, ": command not found", 20);
			putchar('\n');
                }

		if (path != NULL)
		{
			if (exec_cmd(cmd, path) == -1)
			{
				perror("error exec cmd");
				return (-1);
			}
		}

		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}

	free(path);
	free(buffer);
	(void)ac;
	(void)av;
	return (0);
}
