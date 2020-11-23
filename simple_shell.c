#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *buffer = NULL;
	list_t *ptrenv = NULL;
	size_t bufsize = 0;
	int i = 0;

	ptrenv = list_env(env);
	type_prompt(ptrenv);

	while (getline(&buffer, &bufsize, stdin) > 0)
	{
		cmd = split(buffer);

		if (cmd[0] != NULL)
		{
			if (is_built_in(cmd[0]) == 0)
			{
				puts("is built in");
				if (exec_built_in(cmd, ptrenv) == 0)
				{
					free_array(cmd);
					break ;
				}
			}

			else if (get_path(cmd, ptrenv))
			{
				cmd[0] = get_path(cmd, ptrenv);
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

			free_array(cmd);
		}

		type_prompt(ptrenv);
	}

	free_list(ptrenv);
	free(buffer);
	(void)ac;
	(void)av;
	return (0);
}
