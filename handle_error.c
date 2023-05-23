#include "simple_shell.h"

/**
 * not_found - functions that write error
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: environmental variables linked list
 */
void not_found(char *str, int c_n, list_t *env)
{

	int counter = 0;
	char *sh;
	char *number;

	sh = get_env("_", env);
	while (sh[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, sh, counter);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	number = int_to_string(c_n);
	counter = 0;
	while (number[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, number, counter);
	free(number);
	write(STDOUT_FILENO, ": ", 2);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, str, counter);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cant_cd_to - function write error
 * @str: argument after the cmd cd
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write sh name
 */
void cant_cd_to(char *str, int c_n, list_t *env)
{
	int counter = 0;
	char *sh;
	char *number;

	sh = get_env("_", env);
	while (sh[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, sh, counter);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	number = int_to_string(c_n);
	counter = 0;
	while (number[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, number, counter);
	free(number);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, str, counter);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * illegal_number - function that write error
 * @str: typed argument after the cmd exit
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write sh name
 */
void illegal_number(char *str, int c_n, list_t *env)
{
	int counter = 0;
	char *sh = NULL;
	char *number = NULL;

	sh = get_env("_", env);
	while (sh[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, sh, counter);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	number = int_to_string(c_n);
	counter = 0;
	while (number[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, number, counter);
	free(number);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, str, counter);
	write(STDOUT_FILENO, "\n", 1);
}
