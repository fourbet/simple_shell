#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
        char *str;
        struct list_s *next;
} list_t;

/**
 * struct filter - structure with format && return
 * function of pointer
 * @identifier: format
 * @ptr_f: pointer of function
 */
typedef struct filter
{
	char *id;
	int (*ptr_f)(char **, list_t **);
} filt;

int _strncmp(char *s1, char *s2, int n);
int built_in_cd(char **cmd, list_t **env);
int built_in_exit(char **, list_t **);
int _strcmp(char *s1, char *s2);
char **get_copy_env(char **env);
int type_prompt(list_t *ptrEnv);
int _strlen(char *s);
void free_array(char **tab);
int nbr_words(char *str, char *sep);
void print_array(char **tab);
char *_strdup(char *str);
char *_getenv(char *name, list_t **ptrEnv);
int built_in_env(char **, list_t **);
int exec_cmd(char **cmd, char *path);
int exec_builtin(char **cmd, list_t **ptrEnv);
char *_strcat(char *dest, char *src);
char *get_path(char **cmd, list_t *ptrEnv);
char **split(char *buffer);
list_t *add_node_end(list_t **head, const char *str);
list_t *_getenvlinked(void);
list_t *getenvLinked(char **env);
int built_in_setenv(char **cmd, list_t **ptrEnv);
int built_in_unsetenv(char **cmd, list_t **ptrEnv);

#endif
