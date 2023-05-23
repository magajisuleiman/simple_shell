#include "simple_shell.h"

/**
 * c_t_size - function that returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: number of tokens
 */
int c_t_size(char *str, char delm)
{
	int i = 0;
	int delim = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
			delim++;
		i++;
	}
	return (delim);
}

/**
 * c_str_tok - tokenizes a string even the continuous delim with empty string
 * (e.g. path --> ":/bin::/bin/usr" )
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"\0", "/bin", "\0", "/bin/usr"}
 * (purpose is to have which command look through current directory if ":")
 */
char **c_str_tok(char *str, char *delm)
{
	int buff_size = 0;
	int p = 0;
	int sii = 0;
	int i = 0;
	int str_len = 0;
	int see = 0;
	char **tokens = NULL, dd_ch;


	dd_ch = delm[0];


	buff_size = c_t_size(str, dd_ch);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);


	while (str[see] != '\0')
		see++;
	while (sii < see)
	{
		str_len = t_strlen(str, sii, dd_ch);
		tokens[p] = malloc(sizeof(char) * (str_len + 1));
		if (tokens[p] == NULL)
			return (NULL);

		i = 0;
		while ((str[sii] != dd_ch) &&
		       (str[sii] != '\0'))
		{
			tokens[p][i] = str[sii];
			i++;
			sii++;
		}
		tokens[p][i] = '\0';
		p++;
		sii++;
	}
	tokens[p] = NULL;
	return (tokens);
}
