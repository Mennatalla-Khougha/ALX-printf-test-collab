#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
* pr_chr - print a char.
* @s: parameter of type va_list .
* Return: 1.
*/
int print(char s)
{
	return (write(1, &s, 1));
}

/**
 * _printf - print to the screen.
 * @format: a character string.
 * Return: number of character printed to the screen.
*/

int _printf(const char *format, ...)
{
	char p = '%', s, *str, f;
	int sum = 0, i = 0, j;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		f = format[i];
		if (format[i] != '%')
		{
			sum += print(format[i]);
		}
		else
		{	
			if (format[i + 1] == '%')
			{
				s = p;
				print(s);
				i++;
			}
            else if (format[i + 1] == 'c')
            {
                s = va_arg(args, int);
                print(s);
				i++;
            }
			else if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				for (j = 0; j < strlen(str); j++)
				{
					s = str[j];
					print(s);
				}
				i++;
			}
		}
		i++;
	}
		
		va_end(args);
		return (sum);
}

int main(void)
{
	char c = 'H';
	char *s = "Hello world";
	int x;
	x = _printf("this is a test\n%s\n%c\n%%\n", s, c);
	return (x);
}