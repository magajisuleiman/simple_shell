#include "simple_shell.h"

/**
 * _realloc - function to allocate memory and set all values to 0
 * @ptr: previously allocated
 * @old_size: pre allocated size
 * @new_size: new size
 * Return: re allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	void *pp;
	unsigned int j;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		else
			return (pp);
	}

	pp = malloc(new_size);
	if (!pp)
		return (NULL);

	for (j = 0; j < old_size && j < new_size; j++)
		*((char *)pp + j) = *((char *)ptr + j);
	free(ptr);

	return (pp);
}
