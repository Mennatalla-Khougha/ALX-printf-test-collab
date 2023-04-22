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
	char *str = va_arg(args, char *);

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
{'c', pr_chr},
{'s', pr_string},
{'%', pr_chr},
{'\0', NULL}
		};
		va_list args;
		int i = 0, j = 0;
	int num = 0;

		va_start(args, format);
		while (format[i] != '\0')
		{
			for (j = 0; j < 4; j ++)
			{		
				if (chars[j].ch == format[i + 1])
					num = chars[j].ptr(args);

				continue;
			}
			i++;
		}
		
		va_end(args);
		return (num);
}

int main(void)
{
	char c = 'H';
	char *s = "Hello world";
	_printf("%c%s", c, s);
	return (0);
}