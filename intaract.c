#include "simple_shell.h"

/**
 * c_ignore - function that custom ignores spaces and newlines
 * @str: env var
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}


/**
 * non_interactive - function that handles
 * @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t j = 0;
	size_t m = 0;
	int line_no = 0;
	int exit_stat = 0;
	char *command = NULL;
	char *no_command = NULL;
	char **no_line, **tokens;

	j = get_line(&command);
	if (j == 0)
	{
		free(command);
		exit(0);
	}
	no_command = command;
	command = c_ignore(command);
	no_line = _str_tok(command, "\n");
	if (no_command != NULL)
		free(no_command);
	m = 0;
	while (no_line[m] != NULL)
	{
		line_no++;
		tokens = NULL;
		tokens = _str_tok(no_line[m], " ");
		exit_stat = built_in(tokens, env, line_no, no_line);
		if (exit_stat)
		{
			m++;
			continue;
		}
		exit_stat = _execve(tokens, env, line_no);
		m++;
	}
	free_double_ptr(no_line);
	free_linked_list(env);
	exit(exit_stat);
}
