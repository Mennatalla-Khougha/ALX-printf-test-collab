#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * pr_decimal - print a decimal number
 * @args: parameter of va_list
 * Return: 1;
 */
int pr_decimal(va_list args)
{
	int d = va_arg(args, int);
	return (write(1, &d, 1));
}
/**
 * pr_integer - print an integer number
 * @args: parameter of va_list
 * Return: 1
 */
int pr_integer(va_list args)
{
	int i = va_arg(args, int);
	return (write(1, &i, 1));
}
int _printf(const char *format, ...)
