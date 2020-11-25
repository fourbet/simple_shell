#include "holberton.h"

/**
 *_isatty - check isatty
 *@ptrenv: environement
 *Return: void
 */
void _isatty(list_t *ptrenv)
{
	if (isatty(STDIN_FILENO) == 1)
		type_prompt(ptrenv);
}

/**
 * main - simple shell
 * @ac: numbers arguments
 * @av: aray of arguments
 * @env: environnement varriable
 *
 * Return: 0 (SUCCESS)
 */
int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *buffer = NULL, *serror = NULL;
	list_t *ptrenv = NULL;
	size_t bufsize = 0;
	int count = 0;

	ptrenv = list_env(env);
	_isatty(ptrenv);
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
					break;
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
		_isatty(ptrenv);
	}
	free_array(cmd);
	free_list(ptrenv);
	free(buffer);
	(void)ac;
	(void)av;
	return (0);
}
