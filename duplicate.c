#include "simple_shell.h"

/**
 * _strdup - function to returns a pointer to a newly allocated space in memory
 * @str: duplicate of string
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i;
	int str_len = 0;

	if (!str)
		return (NULL);

	while (*(str + str_len))
		str_len++;
	str_len++;

	dup_str = malloc(sizeof(char) * str_len);
	if (!dup_str)
		return (NULL);

	i = 0;
	while (i < str_len)
	{
		*(dup_str + i) = *(str + i);
		i++;
	}

	return (dup_str);
}
