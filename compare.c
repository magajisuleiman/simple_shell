#include "simple_shell.h"

/**
 * _strcmp - function to compare two strings
 * @s1: string 1 to compare
 * @s2: string 2 to be compared
 * Return: int that tells num spaces in between,
 * 0 if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;
	return ((*(s2 + i)) ? (*(s1 + i) - *(s2 + i)) : (0));
}
