#include "simple_shell.h"

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: copy original source
 */

char *_strcpy(char *dest, char *src)
{
	int i, str_len;

	for (str_len = 0; src[str_len] != '\0'; str_len++)
		;

	for (i = 0; i <= str_len; i++)
		dest[i] = src[i];

	return (dest);
}
