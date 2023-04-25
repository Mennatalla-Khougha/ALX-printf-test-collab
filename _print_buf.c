#include "main.h"

/**
 * _print_c - writes a char
 * @c: char to be printed
 * Return: 1 on success
 */
int _print_c(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
/**
 * _printStr - printout a string
 * @str: the string to be printed
 * Return: the output of _printStr
 */
int _printStr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_print_c(str[i]);
	}
	return (1);
}
