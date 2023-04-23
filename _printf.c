#include "main.h"

/**
* check_input - check the format input.
* @format: poiner to be checked.
* Return: 0 lenght > 0, 1 length = 0, -1 format NULL.
*/
int check_input(const char *format)
{
	if (format == NULL)
		exit(-1);
	if (!strlen(format))
		return (1);
	return (0);
}
/**
* _printf - print whatever passed.
* @format: chars to be printed.
* Return: number of chars printed.
*/
int _printf(const char *format, ...)
{
	char *list = "scdi%";
	int sum = 0, i = 0;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += print(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		else if (strchr(list, format[i + 1]) != 0)
				sum += print_spec(format[i + 1], args);
		else
		{
			sum += print(format[i]);
			sum += print(format[i + 1]);
		}
		i += 2;
	}
	va_end(args);
	return (sum);
}

/**
  * print_spec - print the formatted chars.
  * @format: type of formatted..
  * @args: args to be printed..
  * Return: number of chars printed..
 */
int print_spec(char format, va_list args)
{
	int sum = 0;
	char *str;

	if (format == '%')
		sum += print('%');
	else if (format == 'c')
		sum += pr_chr(args);
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str != NULL)
			sum += pr_string(str);
		else
			sum += pr_string("(null)");
	}
	else if (format == 'd')
		sum += pr_decimal(args);
	else if (format == 'i')
		sum += pr_integer(args);
	return (sum);
}
