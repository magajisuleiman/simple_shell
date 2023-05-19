#include "simple_shell.h"

/**
 * _strcat - functions to concatinate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int strlen1 = 0;
	int strlen2 = 0;
	int str_len = 0;
	int i = 0;

	/* find total length of both strings to _realloc */
	while (dest[strlen1] != '\0')
	{
		strlen1++;
		str_len++;
	}
	while (src[strlen2] != '\0')
	{
		strlen2++;
		str_len++;
	}

	/* _realloc because dest was malloced outside of function */
	dest = _realloc(dest, strlen1, sizeof(char) * str_len + 1);

	while (src[i] != '\0')
	{
		dest[strlen1] = src[i];
		strlen1++;
		i++;
	}
	dest[strlen1] = '\0';

	return (dest);
}
