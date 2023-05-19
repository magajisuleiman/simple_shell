#include "simple_shell.h"

/**
 * c_strcat - to concatenate two strings and ignore first character value
 * @dest: destination string to append to
 * @src: source string appended
 * Return: string concatenated detinatio + source
 */
char *c_strcat(char *dest, char *src)
{
	int strlen = 0;
	int strlen2 = 0;
	int str_len = 0;
	int i = 0;

	while (dest[strlen] != '\0')
	{
		strlen++;
		str_len++;
	}
	while (src[strlen2] != '\0')
	{
		strlen2++;
		str_len++;
	}

	dest = _realloc(dest, strlen, sizeof(char) * str_len + 1);

	i = 1; /* ignore the first character */
	while (src[i] != '\0')
	{
		dest[strlen] = src[i];
		strlen++;
		i++;
	}
	dest[strlen] = '\0';

	return (dest);
}

/**
 * c_setenv - Function that custom _setenv by
 * concatenating string first before setting
 * @env: linked list for env variable
 * @name: env name
 * @dir: env directory path
 * Return: 0 on success
 */
int c_setenv(list_t **env, char *name, char *dir)
{
	int count = 0, i = 0;
	char *cat_;
	list_t *hold;

	cat_ = _strdup(name);
	cat_ = _strcat(cat_, "=");
	cat_ = _strcat(cat_, dir);
	count = find_env(*env, name);

	hold = *env;
	while (i < count)
	{
		hold = hold->next;
		i++;
	}
	free(hold->var);
	hold->var = _strdup(cat_);
	free(cat_);
	return (0);
}

/**
 * cd_only - Function that change directory to back_home
 * @env: env list to update path
 * @current: wd
 */
void cd_only(list_t *env, char *current)
{
	char *back_home = NULL;

	back_home = get_env("HOME", env);
	c_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(back_home, F_OK) == 0)
		chdir(back_home);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PWD", current);
	free(current);
	free(back_home);
}
/**
 * cd_execute - Function that executes the cd
 * @env: bring in environmental linked list to update PATH and OLDPWD
 * @current: bring in current working directotry
 * @dir: bring in directory path to change to
 * @str: bring in the 1st argument to write out error
 * @num: bring in the line number to write out error
 * Return: 0 if success 2 if fail
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * _cd - Function that change directory
 * @str: user's typed in command
 * @env: enviromental linked list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **str, list_t *env, int num)
{
	char *curr = NULL, *dir = NULL;
	int exit_stat = 0;

	curr = getcwd(curr, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else /* Usage: cd directory1 */
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_execute(env, curr, dir, str[1], num);
		free(dir);
	}
	else
		cd_only(env, curr);
	free_double_ptr(str);
	return (exit_stat);
}

