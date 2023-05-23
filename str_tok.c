#include "simple_shell.h"

/**
 * t_strlen - functions that returns token's string length for mallocing
 * @str: a token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int counter = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		counter++;
	}
	return (counter);
}

/**
 * t_size - function that returns number of delim
 * @str: command typed into shell
 * @delm: delimeter
 * Return: number of delims
 */
int t_size(char *str, char delm)
{
	int i = 0;
	int num_delms = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{

			num_delms++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{

			num_delms--;
		}
		i++;
	}
	return (num_delms);
}

/**
 * ignore_delm - function returns a version of string
 * @str: string
 * @delm: delimiter
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - function that tokenizes a string
 * @str: command typed into shell
 * @delm: delimeter
 * Return: an array of tokens
 */
char **_str_tok(char *str, char *delm)
{
	int buffsize = 0;
	int p = 0;
	int sii = 0;
	int i = 0;
	int counter = 0;
	int see = 0;
	int tt = 0;
	char **tokens = NULL;
	char dd_ch;

	dd_ch = delm[0];
	/* creates new version of string ignoring all delims infront*/
	str = ignore_delm(str, dd_ch);
	/* malloc ptrs to store array of tokens (buffsize + 1), and NULL ptr */
	buffsize = t_size(str, dd_ch);
	tokens = malloc(sizeof(char *) * (buffsize + 2));
	if (tokens == NULL)
		return (NULL);
	while (str[see] != '\0')	/* find string ending index */
		see++;
	while (sii < see)
	{ /* malloc lengths for each token ptr in array */
		if (str[sii] != dd_ch)
		{
			counter = t_strlen(str, sii, dd_ch);
			tokens[p] = malloc(sizeof(char) * (counter + 1));
			if (tokens[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[sii] != dd_ch) && (str[sii] != '\0'))
			{
				tokens[p][i] = str[sii];
				i++;
				sii++;
			}
			tokens[p][i] = '\0'; /* null terminate at end*/
			tt++;
		}

		if (sii < see && (str[sii + 1] != dd_ch && str[sii + 1] != '\0'))
			p++;
		sii++;
	}
	p++;
	tokens[p] = NULL;
	return (tokens);
}
