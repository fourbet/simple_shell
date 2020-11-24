#include "holberton.h"

/**
 * _strdelete - delete string before the = symbol
 *
 * @string: string to change
 *
 * Return: the string changed
*/
char *_strdelete(char *string)
{
	char *s;
	int i = 0;
	int index = 0;

	s = malloc(sizeof(char) * _strlen(string));
	while (string[i] != '\0')
	{
		if (string[i] == '=')
		{
			index = i;
			break;
		}
		i++;
	}
	i = 0;
	index++;
	while (string[index] != '\0')
	{
		s[i] = string[index];
		index++;
		i++;
	}
	return (s);
}
/**
 * _getenv - get the value of the variable name
 *
 * @name: variable
 * @ptrEnv: environnement variable
 *
 * Return: the value corresponding
 */
char *_getenv(char *name, list_t **ptrEnv)
{
	char *env = NULL;
	list_t *current;

	current = *ptrEnv;
	while (current)
	{
		if ((_strncmp(current->str, name, _strlen(name)) == 0))
		{
			env = _strdelete(current->str);
			break;
		}
		current = current->next;
	}
	return (env);
}
