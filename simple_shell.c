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

void sig_ctrl_c(int sig)
{
	write(STDOUT_FILENO,"\n$ ", 3);
	(void)sig;
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
	char *buffer = NULL, *resgetpath = NULL;
	list_t *ptrenv = NULL;
	size_t bufsize = 0;
	int count = 0;

	ptrenv = list_env(env);
	_isatty(ptrenv);
	signal(SIGINT, sig_ctrl_c);
	while (getline(&buffer, &bufsize, stdin) != EOF)
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
					break;
				}
			}
			else
			{
				resgetpath = get_path(cmd, ptrenv);
				if (resgetpath != NULL)
				{
					cmd[0] = resgetpath;
					exec_cmd(cmd);
				}
				else
					seterror(cmd[0], count);
			}
			free_array(cmd);
		}
		_isatty(ptrenv);
	}
	free_list(ptrenv);
	free(buffer);
	(void)ac;
	(void)av;
	return (0);
}
