#include "simple_shell.h"

/**
 * numlen - function that counts number of 0s
 * @n: number
 * Return: returns index
 */
int numlen(int n)
{
	int index = 0;
	int number  = n;

	while (number  > 9 || number  < -9)
	{
		number  /= 10;
		index++;
	}
	return (index);
}
/**
 * int_to_string - turns an int into a string
 * @number: int
 * Return: returns the int as a string. returns NULL if failed
 */

char *int_to_string(int number)
{
	int digt;
	int ten;
	int j = 0;
	int z = 0;
	int y;
	char *ress;

	digt = number;
	ten = 1;

	if (number < 0)
		z = 1;
	ress = malloc(sizeof(char) * (numlen(digt) + 2 + z));
	if (ress == NULL)
		return (NULL);
	if (number < 0)
	{
		ress[j] = '-';
		j++;
	}
	for (y = 0; digt > 9 || digt < -9; y++)
	{
		digt = digt / 10;
		ten = digt * 10;
	}
	for (digt = number; y >= 0; y--)
	{
		if (digt < 0)
		{
			ress[j] = (digt / ten) * -1 + '0';
			j++;
		}
		else
		{
			ress[j] = (digt / ten) + '0';
			j++;
		}
		digt %= ten;
		ten /= 10;
	}
	ress[j] = '\0';
	return (ress);
}
