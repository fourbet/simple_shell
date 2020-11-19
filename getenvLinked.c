#include "holberton.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 *
 * @head: pointer to a pointer to a list_t
 *
 * @str: const string
 *
 * Return: the adress of the new element or NULL if failed
 */

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
                {
                        current = current->next;
                }
                current->next = new;
        }
        return (new);
}


list_t *getenvLinked(char **env)
{
        int i = 0;
        list_t *head;

        head = NULL;
        while (env[i] != NULL)
        {
                add_node_end(&head, env[i]);
                i++;
        }
        return(head);
}
