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
 * struct filter - structure with format && return
 * function of pointer
 * @identifier: format
 * @ptr_f: pointer of function
 */
typedef struct filter
{
	char *id;
	int (*ptr_f)(void);
} filt;

int built_in_exit(void);
int _strcmp(char *s1, char *s2);
char **get_copy_env(char **env);
int type_prompt(void);
int _strlen(char *s);
void free_array(char **tab);
int nbr_words(char *str, char *sep);
void print_array(char **tab);
char *_strdup(char *str);
char *_getenv(const char *name);
int built_in_env(void);
int exec_cmd(char **cmd, char *path);
int exec_builtin(char *cmd);
char *_strcat(char *dest, char *src);
char *get_path(char **cmd);
char **split(char *buffer);


typedef struct element_t
{
	char *str;
	unsigned int len;
	struct element_t *next;
} list_t;

#endif
