#include "simple_shell.h"

/**
 * ctrl_c - function that ignore Ctrl-C input
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - function that handles builtins
 * @tokens: typed command by users
 * @env: environmental variable
 * @num: nth user command
 * @command: command to free
 * Return: 1 if success
 */
int built_in(char **tokens, list_t *env, int num, char **command)
{
	int j = 0;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		j = __exit(tokens, env, num, command);
	}


	else if (_strcmp(tokens[0], "env") == 0)
	{
		_env(tokens, env);
		j = 1;
	}


	else if (_strcmp(tokens[0], "cd") == 0)
	{
		j = _cd(tokens, env, num);
	}


	else if (_strcmp(tokens[0], "setenv") == 0)
	{
		_setenv(&env, tokens);
		j = 1;
	}


	else if (_strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(&env, tokens);
		j = 1;
	}
	return (j);
}


/**
 * ignore_space - function that return string
 * @str: str
 * Return: string of new
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}


/**
 * ctrl_D - function to exit the program
 * @j: read characters
 * @command: typed in command by users
 * @env: var linked list
 */

void ctrl_D(int j, char *command, list_t *env)
{
	if (j == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - function to repeatedly prompts user
 * @en: env var
 * Return: 0 on success
 */
int prompt(char **en)
{
	list_t *env;
	size_t j = 0;
	size_t n = 0;
	int command_lines_no = 0;
	int exit_stat = 0;
	char *commands;
	char *n_commands;
	char **tokens;

	env = env_linked_list(en);

	while (1)
	{
		command_lines_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		commands = NULL;
		j = 0;
		j = get_line(&commands);
		ctrl_D(j, commands, env);
		n_commands = commands;
		commands = ignore_space(commands);
		n = 0;
		while (commands[n] != '\n')
			n++;
		commands[n] = '\0';
		if (commands[0] == '\0')
		{
			free(n_commands);
			continue;
		}
		tokens = NULL;
		tokens = _str_tok(commands, " ");
		if (n_commands != NULL)
			free(n_commands);
		exit_stat = built_in(tokens, env, command_lines_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(tokens, env, command_lines_no);
	}

	return (exit_stat);
}
