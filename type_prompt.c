#include "holberton.h"

/**
 *type_prompt - set the prompt
 *@ptrEnv: environement
 *Return: integer
 */
int type_prompt(list_t *ptrEnv)
{
	char *prompt = NULL;

	prompt = "$ ";
	if (_getenv("PS1", &ptrEnv) != NULL)
		prompt = _getenv("PS1", &ptrEnv);

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}
