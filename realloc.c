#include "holberton.h"

/**
 *_realloc - reallocates a memory block
 * @ptr : original allocated pointer
 * @old_size : original size
 * @new_size : new size
 * Return: pointer to allocated memory, NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *s;

	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (s == NULL)
			return (NULL);
		return (s);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	s = malloc(new_size);
	if (s == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)s + i) = *((char *)ptr + i);
	free(ptr);
	return (s);
}
