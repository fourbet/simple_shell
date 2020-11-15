#ifndef HOLBERTON_H
#define HOLBERTON_H

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

char **get_copy_env(char **env);
int type_prompt(char **env);
int _strlen(char *s);
void free_array(char **tab);
int nbr_words(char *str, char *sep);
void print_array(char **tab);
char *_strdup(char *str);
int builtin_env(void);

#endif
