#include "simple_shell.h"

/**
 * _which - function that fleshes out command
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
	char *path;
	char *cate = NULL;
	char **tokens;
	int i = 0;


	path = get_env("PATH", env);
	tokens = c_str_tok(path, ":");
	free(path);


	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			cate = getcwd(cate, 0);
		else
			cate = _strdup(tokens[i]);
		cate = _strcat(cate, "/");
		cate = _strcat(cate, str);
		if (access(cate, F_OK) == 0)
		{

			free_double_ptr(tokens);
			return (cate);
		}
		free(cate);
		i++;
	}
	free_double_ptr(tokens);
	return (str);
}
