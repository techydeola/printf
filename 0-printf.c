#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void print_char(char ch);
void print_string(char *str);

void print_char(char ch)
{
	putchar(ch);
}

void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}

int _printf(const char *format, ...)
{
	int i = 0;
	int len = 0;
	va_list ap;
	char ch;
	char *str;

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
			{
				putchar('%');
			}

			else
			{
				putchar('%');
				putchar(format[i]);
			}
		}
		else
			putchar(format[i]);
		i++;
		len++;
	}
	va_end(ap);

	return (len - 1);
}
