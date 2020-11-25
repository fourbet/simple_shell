#include "holberton.h"

/**
 * _strcat2 - concate the name and the value with the symbole =
 *
 * @name: string containing the name of the env variable
 * @value: string containing the value of the env variable
 *
 * Return: string concatenated
 */
char *_strcat2(char *name, char *value)
{
	char *s;
	int i = 0;
	int j = 0;

	s = malloc(sizeof(char) * _strlen(name) + _strlen(value) + 2);
	while (name[i] != '\0')
	{
		s[i] = name[i];
		i++;
	}
	s[i] = '=';
	i++;
	while (value[j] != '\0')
	{
		s[i] = value[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}
/**
 * built_in_setenv - add new var env or modify existing one
 *
 * @cmd: arguments of the command
 * @ptrEnv: list of environnement var
 *
 * Return: 1(SUCCESS)
 */
int built_in_setenv(char **cmd, list_t **ptrEnv)
{
	int i = 0, passed = 0;
	list_t *current;
	char *variable;
	char *value;

	while (cmd[i] != NULL)
		i++;
	if (i != 3 || ptrEnv == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 8);
		return (1);
	}
	current = *ptrEnv;
	variable = cmd[1];
	value = cmd[2];
	while (current)
	{
		if ((_strncmp(current->str, variable, _strlen(variable)) == 0))
		{
			current->str = _strcat2(variable, value);
			passed = 1;
			break;
		}
		current = current->next;
	}
	if (passed == 0)
	{
		add_node_end(ptrEnv, _strcat2(variable, value));
	}
	return (1);
}
/**
 * built_in_unsetenv - delete a environnement variable
 *
 * @cmd: arguments
 * @ptrEnv: list of environnement var
 *
 * Return: 1(SUCCESS)
 */
int built_in_unsetenv(char **cmd, list_t **ptrEnv)
{
	int i = 0;
	char *variable;
	list_t *current;
	list_t *previous;
	int count = 0;

	while (cmd[i] != NULL)
		i++;

	if (i != 2 || ptrEnv == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 8);
		return (1);
	}
	current = *ptrEnv;
	variable = _strdup(cmd[1]);
	while (current)
	{
		if ((_strncmp(current->str, variable, _strlen(variable)) == 0))
		{
			if (count != 0)
			{
				previous->next = current->next;
			}
			else
			{
				*ptrEnv = current->next;
			}
			free(current->str);
			free(current);
			free(variable);
			return (1);
		}
		count++;
		previous = current;
		current = current->next;
	}
	write(STDERR_FILENO, "Variable does not exist\n", 24);
	return (1);
}
