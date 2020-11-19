#include "holberton.h"

int type_prompt(list_t *ptrEnv)
{
	char *prompt = NULL;

	prompt = "$ ";
       	if (_getenv("PS1", &ptrEnv) != NULL)
	{
		prompt = _getenv("PS1", &ptrEnv);
		printf("prompt : %s\n", prompt);
	}
	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}
