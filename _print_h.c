#include "main.h"

/**
 * pr_hexa - print hexa numbers.
 * @args: numbers to be printed.
 * Return: number of digits to be printed.
 */

int pr_hexa(va_list args, int n)
{
	int sum = 0;
	unsigned int num = va_arg(args, unsigned int);

	return (print_h(num, sum, n));
}

/**
 * print_h - convert into to hexa.
 * @n: number to be converted.
 * @sum: 0
 * char:55 or 87.
 * Return: number of digits printed.
 */

int print_h(unsigned int n, int sum, int chr)
{
	unsigned int x = n;

	x /= 16;
	if (x != 0)
		sum = print_h(x, sum, chr);
	if (n % 16 < 9)
		sum += print('0' + n % 16);
	else
		sum += print(chr + n % 16);
	return (sum);
}
