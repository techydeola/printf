#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - a function that prints single character
 * @ch: character to be printed
 *
 */

void print_char(char ch)
{
	_putchar(ch);
}

/**
 * print_string - a function that print strings
 * @str: pointer to the string to be printed
 */
void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _printf - a function that produces output according to a format
 * @format: first argument
 * @...: other variadic arguments
 *
 * Return: length of the characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int len = 0;
	int dubl, int num;
	va_list ap;
	char ch, *str;

	if (format == NULL)
		exit(1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == 'c')
			{
				ch = (char)va_arg(ap, int);
				print_char(ch);
			}
			else if (format[i] == 's')
			{
				str = (va_arg(ap, char *));
				print_string(str);
			}
			else if (format[i] == '%')
				_putchar('%');
			else if (format[i] == 'd')
			{
				dubl = va_arg(ap, double);
				write(1, &dubl, sizeof(double));
			}
			else if (format[i] == 'i')
			{
				num = va_arg(ap, int);
				write(1, &num, sizeof(int));
			}
			else
				handle_other(&format[i], ap);
		}
		else
			_putchar(format[i]);
		i++;
		len++;
	}
	va_end(ap);
	return (len - 1);
}
