#include "simple_shell.h"

/**
 * get_line - function that stores into malloced buffer
 * @str: buffer
 * Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0;
	ssize_t buff_size = 0;
	ssize_t p = 0;
	ssize_t p2 = 0;
	ssize_t n = 0;
	char buffer[1024];



	while (p2 == 0 && (i = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buffer[i] = '\0';

		n = 0;
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '\n')
				p2 = 1;
			n++;
		}


		if (p == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buffer);
			buff_size = i;
			p = 1;
		}
		else /* _realloc via _strcat with each loop */
		{
			buff_size += i;
			*str = _strcat(*str, buffer);
		}
	}
	return (buff_size);
}
