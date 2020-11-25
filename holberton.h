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

void _isatty(list_t *ptrenv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strncmp(char *s1, char *s2, int n);
int built_in_cd(char **cmd, list_t *env);
int built_in_exit(char **);
int _strcmp(char *s1, char *s2);
char **get_copy_env(char **env);
int type_prompt(list_t *ptrEnv);
int _strlen(char *s);
void free_array(char **tab);
size_t nbr_words(char *str, char *sep);
void print_array(char **tab);
char *_strdup(char *str);
char *_getenv(char *name, list_t **ptrEnv);
int built_in_env(list_t *);
int exec_cmd(char **cmd);
int exec_built_in(char **cmd, list_t *ptrEnv);
char *_strcat(char *dest, char *src);
char *get_path(char **cmd, list_t *ptrEnv);
char **split(char *buffer);
list_t *add_node_end(list_t **head, char *str);
list_t *list_env(char **env);
int built_in_setenv(char **cmd, list_t **ptrEnv);
int built_in_unsetenv(char **cmd, list_t **ptrEnv);
char *get_cd_path(char **cmd, list_t *env);
char *_getcwd(list_t **env);
int is_built_in(char *cmd);
void free_list(list_t *head);
char *seterror(char *cmd, int count);
int _atoi(char *str);
char *_itoa(int num, char *str);
int built_in_help(char **cmd);

#endif
