#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *buffer = NULL;
	size_t bufsize = 1024;
	int i = 0;

	buffer = malloc(sizeof(char) * bufsize);
	type_prompt();

	while (getline(&buffer, &bufsize, stdin) > 0)
	{
		cmd = split(buffer);
		if (cmd[0] == NULL)
			perror("error split");

		if (is_built_in(cmd[0]) == 1)
		{
			if (!exec_built(cmd))
			{
				free_array(cmd);
				break ;
			}
		}

		else if (get_path(cmd))
		{
			cmd[0] = get_path(cmd);
			exec_cmd(cmd);
		}
		else
                {
			i = 0;
                        while (cmd[i])
                        {
				write(1, "sh: ", 5);
                                write(1, cmd[i], _strlen(cmd[i]));
                                i++;
                        }
                        write(1, ": not found", 20);
			putchar('\n');
                }

		type_prompt();
		free_array(cmd);
	}

	free(buffer);
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}
