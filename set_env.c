#include "simple_shell.h"

/**
 * find_env - function that find given environmental variable
 * @env: env var linked
 * @str: var name
 * Return: idx of node
 */
int find_env(list_t *env, char *str)
{
	int i = 0;
	int idx = 0;


	while (env != NULL)
	{
		i = 0;
		while (((*env).var)[i] == str[i]) /* find desired env variable */
			i++;
		if (str[i] == '\0') /* if matches entirely, break, return idx */
			break;
		env = (*env).next;
		idx++;
	}
	if (!env)
		return (-1);
	return (idx);
}

/**
 * _unsetenv - find remove node in env
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success
 */
int _unsetenv(list_t **env, char **str)
{
	int idx = 0;
	int i = 0;

	if (!str[1])
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	idx = find_env(*env, str[1]);
	free_double_ptr(str);
	if (idx == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	i = delete_nodeint_at_index(env, idx);
	if (i == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenv - function that create or modify existing env var
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success, 1 on failure
 */
int _setenv(list_t **env, char **str)
{
	int idx = 0;
	int i = 0;
	char *cate;
	list_t *hld;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	cate = _strdup(str[1]);
	cate = _strcat(cate, "=");
	cate = _strcat(cate, str[2]);
	idx = find_env(*env, str[1]);
	if (idx == -1)
	{
		add_end_node(env, cate);
	}
	else
	{
		hld = *env;
		while (i < idx)
		{
			hld = hld->next;
			i++;
		}
		free(hld->var); /* else free malloced data */
		hld->var = _strdup(cate); /* assign to new malloced data */
	}
	free(cate);
	free_double_ptr(str);
	return (0);
}
