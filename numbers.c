#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_int - function that prints an integer
 * @a: passed integer
 */
void print_int(int a)
{
	if (a != '\0')
	{
		if (a <= 9)
			_putchar(a + '0');
		else if (a >= 10 && a <= 99)
		{
			_putchar((a / 10) + '0');
			_putchar((a % 10) + '0');
		}
	}
}

/**
 * numbers - variadic function that checks and returns integer values
 * @format: first input
 * @...: other inputs
 * Return: total length of the input
 */
int numbers(const char *format, ...)
{
	int dubl, num;
	int total = 0;
	int i = 0;
	va_list ap;

	if (format == NULL)
		exit(1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				dubl = va_arg(ap, double);
				print_int(dubl);
			}
			else if (format[i] == 'i')
			{
				num = va_arg(ap, int);
				print_int(num);
			}
			else
				handle_other(&format[i], ap);
		}
		i++;
		total++;
	}
	va_end(ap);
	return (total);
}
