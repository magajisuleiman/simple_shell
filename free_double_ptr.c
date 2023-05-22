#include "simple_shell.h"

/**
 * free_double_ptr - functions that free malloced arrays
 * @str: array of strings
*/
void free_double_ptr(char **str)
{
	int i;

	i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
