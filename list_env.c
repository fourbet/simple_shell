#include "holberton.h"

/**
 *free_list - free linked list
 *@head: linked list
 *Return: void
 */
void free_list(list_t *head)
{
	list_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}

/**
 *add_node_end - add cell at the end of linked list
 *@head: adress of the linked list
 *@str: node to add
 *Return: Linked list update
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new = NULL;
	list_t *current = NULL;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (new);
}

/**
 *list_env - create a list of environement variable
 *@env: environement
 *Return: linked list
 */
list_t *list_env(char **env)
{
	int i = 0;
	list_t *head = NULL;

	while (env[i])
	{
		add_node_end(&head, env[i]);
		i++;
	}
	return (head);
}
