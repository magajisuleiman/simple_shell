#include "simple_shell.h"

/**
 * c_strdup - fuction that customize strings
 * @str: PATH=/bin:/bin/ls
 * @cs: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string
 */
char *c_strdup(char *str, int cs)
{
	char *dup_str;
	int i;
	int len_str = 0;

	if (!str)
		return (NULL);

	while (*(str + len_str))
		len_str++;
	len_str++;


	dup_str = malloc(sizeof(char) * (len_str - cs));
	if (!dup_str)
		return (NULL);

	i = 0;
	while (i < (len_str - cs))
	{
		*(dup_str + i) = *(str + cs + i);
		i++;
	}
	return (dup_str);
}

/**
 * get_env - finds and returns a copy of the requested environmental variable
 * @str: string to store
 * @env: set of environmental variables
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{

	int i = 0;
	int css = 0;


	while (env != NULL)
	{
		i = 0;
		while ((env->var)[i] == str[i])
			i++;
		if (str[i] == '\0' && (env->var)[i] == '=')
			break;
		env = env->next;
	}

	while (str[css] != '\0')
		css++;
	css++;
	return (c_strdup(env->var, css));
}
