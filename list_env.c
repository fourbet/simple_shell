#include "holberton.h"

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

list_t *add_node_end(list_t **head, const char *str)
{
        list_t *new;
        list_t *current;

        new = malloc(sizeof(list_t));
        if (new == NULL)
                return (NULL);
        new->str = strdup(str);
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


list_t *list_env(char **env)
{
        int i = 0;
        list_t *head = NULL;

        while (env[i])
        {
                add_node_end(&head, env[i]);
                i++;
        }
        return(head);
}
