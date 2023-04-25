#include "main.h"

/**
 * pr_binary - prints a binary number from int
 * @args: number to be converted
 * Return: number of char printed
 */
int pr_binary(va_list args)
{
	int sum = 0;

	unsigned int b = va_arg(args, unsigned int);

	return (print_b(b, sum, 2));
}

/**
 * print_b - convert int to binary or octal
 * @n: number to be converted
 * @sum: 0.
 * @base: 2 or 8.
 * Return: number of char printed
 */
int print_b(unsigned int n, int sum, int base)
{
	unsigned int x = n;

	x /= base;

	if (x != 0)
		sum = print_b(x, sum, base);
	sum += print('0' + n % base);
	return (sum);
}

/**
 * pr_octal - convert int into octal
 * @args: numbers to be converted
 * Return: number of digist printed.
 */
int pr_octal(va_list args)
{
	int sum = 0;
	unsigned int o = va_arg(args, unsigned int);

	return (print_b(o, sum, 8));
}
