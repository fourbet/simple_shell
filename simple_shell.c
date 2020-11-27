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
 *sig_ctrl_c - printf prompt when we type ^C
 *@sig: integer
 *Return: void
 */
void sig_ctrl_c(int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	(void)sig;
}
/**
 * built_function - part 2 main
 * @resBuilt: int
 * @cmd: char **
 * @count: size_t
 * @ptrenv: list_t *
 *
 *Return: void
 */
void built_function(int resBuilt, char **cmd, size_t count, list_t *ptrenv)
{
	if (resBuilt == 0)
	{
		free_array(cmd);
	}
	if (resBuilt == 99)
	{
		errorBuilt(cmd[1], count);
		free_array(cmd);
		free_list(ptrenv);
		exit(2);
	}
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
	int resBuilt = 0;
	size_t bufsize = 0, count = 0;

	ptrenv = list_env(env);
	_isatty(ptrenv);
	signal(SIGINT, sig_ctrl_c);
	while (getline(&buffer, &bufsize, stdin) != EOF)
	{		count++;
		cmd = split(buffer);
		if (cmd && cmd[0])
		{
			if (is_built_in(cmd[0]) == 0)
			{
				resBuilt = exec_built_in(cmd, ptrenv);
				built_function(resBuilt, cmd, count, ptrenv);
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
