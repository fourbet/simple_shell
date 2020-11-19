#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *path;
	char *buffer = NULL;
	size_t bufsize = 0;
	int i = 0;
	int built = 0;

	type_prompt();
	while (1 && (getline(&buffer, &bufsize, stdin) != EOF))
	{
/*		if (getline(&buffer, &bufsize, stdin) == EOF)
			return (0);
*/
		if (_strcmp(&buffer[0],"\n") != 0)
		{
			/*if (getline(&buffer, &bufsize, stdin) <= 0)
			{
				perror("error getline");
				}*/
			cmd = split(buffer);
			if (cmd == NULL)
			{
				perror("error split");
				return (-1);
			}
			built = exec_builtin(cmd[0]);
			if (built == 0)
				return (0);
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
		type_prompt();
	}

	free(path);
	free(buffer);
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}
