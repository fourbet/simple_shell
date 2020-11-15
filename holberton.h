#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct element_t
{
	char *str;
	unsigned int len;
	struct element_t *next;
} list_t;

#endif
