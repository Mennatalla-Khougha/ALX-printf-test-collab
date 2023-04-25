#include "main.h"

/**
 * pr_pointer - print pointer to the screer.
 * @args: digit to be printed.
 * Return: number of digits to be printed.
 */

int pr_pointer(va_list args)
{
	int sum = 0;
	unsigned long int p = va_arg(args, unsigned long int);

	sum += print('0');
	sum += print('x');
	return (sum + print_p(p, 0));
}

/**
 * print_p - convert unsigned long into hexa
 * @p: number to be converted.
 * @sum: number of digits rpinted on the screen
 * Return: number of digits printed on the screen.
 */

int print_p(unsigned long int p, int sum)
{
	unsigned long int x = p;

	if (x == 0)
		return (pr_string("(nil)"));
	x /= 16;
	if (x != 0)
		sum = print_p(x, sum);
	if (p % 16 <= 9)
		sum += print('0' + p % 16);
	else
		sum += print(87 + p % 16);
	return (sum);
}
