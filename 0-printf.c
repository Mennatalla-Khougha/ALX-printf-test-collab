#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
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
 * pr_percent - print percent.
 * Return: 1;
*/

int pr_percent(void)
{
	char a = '%';

	return(write(1, &a, 1));
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
{'\0', NULL}
		};
		va_list args;
		int i = 0, j = 0;
	int num = 0;
	char new_line = '\n';

		va_start(args, format);
		while (format[i] != '\0')
		{
			if (format[i] == '\n')
			{
				write(1, &new_line, 1);
					i++;
					continue;
			}
			if (format[i + 1] == '%')
			{
				pr_percent();
				num++;
				i += 2;
				continue;;
			}		
			else 
			{
				for (j = 0; j < 3; j ++)
				{
					if (chars[j].ch == format[i + 1])
					{
						num += chars[j].ptr(args);
						i++;
						break;
					}
				}
			}
			i++;
		}
		
		va_end(args);
		return (num);
}

int main(void)
{
	// char c = 'H';
	// char *s = "Hello world";
	_printf("%c%%%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', '\0');
	return (0);
}