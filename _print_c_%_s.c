#include "main.h"

/**
* print - print a char.
* @s: char to be printed..
* Return: 1.
*/
int print(char s)
{
        return (write(1, &s, 1));
}

/**
  * pr_chr - print fornatted char.
  * @args: parameter of type va_list to be printed.
  * Return: 1.
 */
int pr_chr(va_list args)
{
        char s = va_arg(args, int);

        return (print(s));
}

/**
  * pr_string - print formatted string.
  * @str: string to be printed..
  * Return: number of chars printed.
 */
int pr_string(char *str)
{
        int sum = 0, j;
        char s;

        for (j = 0; j < (int)strlen(str); j++)
        {
                s = str[j];
                sum += print(s);
        }
        return (sum);
}