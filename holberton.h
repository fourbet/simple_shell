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

int _strcmp(const char *init, char *other);
char **get_copy_env(char **env);
int type_prompt(char **env);
int _strlen(char *s);
void free_array(char **tab);
int nbr_words(char *str, char *sep);
void print_array(char **tab);
char *_strdup(char *str);
char *_getenv(const char *name);
void built_in_env(void);
int exec_cmd(char **cmd, char *path);
int exec_built(char **cmd);
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
