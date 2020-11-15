#include "holberton.h"

int type_prompt(char ** env)
{
	char *prompt = NULL;
	
	prompt = "$ ";
       	if (_getenv("PS1") != NULL)
		prompt = _getenv("PS1");
	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}
