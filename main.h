#ifndef _MAIN_H_
#define _MAIN_H_
int pr_chr(va_list args);
int pr_string(va_list args);
/**
* struct op - Struct op
*
* @op: The operator
* @f: The function associated
*/
typedef struct ch
{
char *ch;
int (*ptr)(va_list args);
} ch_t;
int _printf(const char *format, ...);
#endif
