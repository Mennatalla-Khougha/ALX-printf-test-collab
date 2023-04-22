#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
* pr_chr - print a char.
* @args: parameter of type va_list .
* Return: 1.
*/
int pr_chr(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
* pr_string - print a string
* @args: parameter of type va_list.
* Return: number of characters printed.
*/
int pr_string(va_list args)
{
	char *str = va_arg(args, char*);

	return (write(1, &str, strlen(str)));
}

/**
 * _printf - print to the screen.
 * @format: a character string.
 * Return: number of character printed to the screen.
*/

int _printf(const char *format, ...)
{
ch_t chars[] = {
{"c", pr_chr},
{"s", pr_string},
{"%", pr_chr},
{NULL, NULL}
		};
		va_list args;
		int i = 0;
	int num = 0;

		va_start(args, format);
		while (chars[i].ch != NULL)
		{
			if (strcmp(chars[i].ch, va_arg(args, char *)) == 0)
			{
				num = chars[i].ptr(args);
			}
			i++;
		}
		va_end(args);
		return (num);
}
