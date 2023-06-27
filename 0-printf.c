#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - a function that prints single character
 * @ch: character to be printed
 *
 * Return: (1)
 */

int print_char(char ch)
{
	_putchar(ch);
	return (1);
}

/**
 * print_string - a function that print strings
 * @str: pointer to the string to be printed
 */
int print_string(char *str)
{
	int i = 0;
	int len;

	if (str == NULL)
	{
		const char *nullstr = "(null)";

		len = _strlen(str);

		while (nullstr[i] != '\0')
		{
			_putchar(nullstr[i]);
			i++;
			return (len);
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			len = _strlen(str);

			_putchar(str[i]);
			i++;
		}
	}
	return (len);
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
	va_list ap;
	char ch, *str;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
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
			else
				handle_other(&format[i], ap);
		}
		else
			_putchar(format[i]);
		i++;
		len++;
	}
	va_end(ap);
	return (len);
}
