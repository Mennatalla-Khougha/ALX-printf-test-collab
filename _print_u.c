#include "main.h"

/**
 * pr_unsigned - print unsigned number.
 * @args: number to be printed.
 * Return: number of digits printed.
 */

int pr_unsigned(va_list args)
{
	int sum = 0;

	unsigned int u = va_arg(args, unsigned int);
	return(print_num(u, sum));
}

/**
 * print_num - print unsigned number.
 * @u: number to be printed.
 * @sum: number of digits printed.
 * Return: number of digits printed.
 */

int print_num(unsigned int u, int sum)
{
	unsigned int x = u;

	x /= 10;
	if (x != 0)
		sum = print_num(x, sum);
	sum += print('0' + u % 10);
	return (sum);
}
