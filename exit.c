#include "simple_shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *s)
{
	int i = 0;
	unsigned int count = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			count = count * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (count);
}

/**
 * __exit - fnction that frees user input and
 * then exits main program with a value
 * @str: command into shell (e.g. "exit 99")
 * @env: environmental variable to free at error
 * @count: user command line input to print in error message
 * @command: command to free
 * Return: 0 if success
 */
int __exit(char **str, list_t *env, int count, char **command)
{
	int value = 0;

	if (str[1] != NULL)
		value = c_atoi(str[1]);

	if (value == -1)
	{
		illegal_number(str[1], count, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(value);
}
