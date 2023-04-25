#include "main.h"

/**
 * print_number - print a number
 * @n: a number.
 * @sum: 0.
 * Return: number of chars printed;
 */

int print_number(int n, int sum)
{
	unsigned int x = n;

	if (n < 0)
	{
		n *= -1;
		x = n;
		sum += print('-');
	}
	x /= 10;
	if (x != 0)
		sum += print_number(x, sum);
	sum += print('0' + (unsigned int) n % 10);
	return (sum);
}

/**
 * pr_decimal - print a decimal number
 * @args: parameter of va_list
 * Return: 1;
 */
int pr_decimal(va_list args)
{
	int sum = 0;
	int d = va_arg(args, int);

	return (print_number(d, sum));
}
/**
 * pr_integer - print an integer number
 * @args: parameter of va_list
 * Return: 1
 */
int pr_integer(va_list args)
{
	int sum = 0;
	int i = va_arg(args, int);

	return (print_number(i, sum));
}
