#include "main.h"

/**
 * pr_str - print the hexa number of unprintable chars.
 * @args: string to be printed
 * Return: number of chars printed.
 */

int pr_str(va_list args)
{
	char *str = va_arg(args, char *);

	return (print_str(str));
}

/**
 * print_str - print the hexa number of unprintable chars.
 * @str: string to be printed.
 * Return: number of chars printed.
 */

int print_str(char *str)
{
	int i, sum = 0, len;

	len = (int)strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			sum += print('\\');
			sum += print('x');
			if (str[i] < 16)
				sum += print('0');
			sum += print_h(str[i], 0, 55);
		}
		else
			sum += print(str[i]);
	}
	return (sum);
}
