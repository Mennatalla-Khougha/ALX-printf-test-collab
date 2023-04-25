#include "main.h"

/**
 * pr_rev - print a string in reverse.
 * @args: string to be printed.
 * Return: the number of chars printed.
 */

int pr_rev(va_list args)
{
	int sum = 0, len, i;
	char *str = va_arg(args, char *);

	len = (int)strlen(str) - 1;
	for (i = len; i >= 0; i--)
	{
		sum += print(str[i]);
	}
	return (sum);
}

/**
 * pr_rot - print the rot13 string.
 * @args: string to be rotated.
 * Return: number of chars printed.
 */

int pr_rot(va_list args)
{
	char *str = va_arg(args, char *);

	return (print_rot(str));
}

/**
 * print_rot - print the rot13 string.
 *@str: string to be rotated.
 * Return: number of chars printed.
 */

int print_rot(char *str)
{
	int i = 0, j, sum = 0;
	char *alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *code = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char s;

	while (str[i])
	{
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
		{
			s = str[i];
			sum += print(s);
		}
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == alph[j])
			{
				s = code[j];
				sum += print(s);
				break;
			}
		}
		i++;
	}
	return (sum);
}
