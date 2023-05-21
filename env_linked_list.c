#include "simple_shell.h"

/**
 * env_linked_list - function that creates list from env var
 * @env: env variables
 * Return: list linked
 */
list_t *env_linked_list(char **env)
{
	list_t *hd;
	int i;

	i = 0;

	hd = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&hd, env[i]);
		i++;
	}
	return (hd);
}

/**
 * _env - funtions that print env factors
 * @str: user's command into shell
 * @env: env variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}
