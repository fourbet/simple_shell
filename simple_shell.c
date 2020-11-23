#include "holberton.h"

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *buffer = NULL;
	list_t *ptrenv = NULL;
	char *serror = NULL;
	size_t bufsize = 0;
	int i = 0;
	int count = 0;

	ptrenv = list_env(env);
	type_prompt(ptrenv);
	signal(SIGINT, SIG_IGN);
	while (getline(&buffer, &bufsize, stdin) > 0)
	{
		count++;
		cmd = split(buffer);

		if (cmd[0] != NULL)
		{
			if (is_built_in(cmd[0]) == 0)
			{
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
				serror = seterror(cmd[0], count);
				write(STDOUT_FILENO, serror, _strlen(serror));
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
