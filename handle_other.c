#include "main.h"
#include <stdarg.h>

/**
 * handle_other - this function handles other format specifier
 * @format: first argument
 * @ap: second argument
 */

void handle_other(const char *format, va_list ap)
{
	if (*format == 'b')
	{
		unsigned int num = va_arg(ap, unsigned int);
		int cont = 0;
		int i;

		for (i = 31; i >= 0; i--)
		{
			int digit = (num >> 1) & 1;

			if (digit || cont > 0)
			{
				_putchar(digit + '0');
				cont++;
			}
		}

		if (cont == 0)
		{
			_putchar('0');
			cont++;
		}
	}
	if (*format == 'd')
	{
		int num = va_arg(ap, int);

		print_int(num);
	}
	if (*format == 'i')
	{
		int num = va_arg(ap, int);

		print_int(num);
	}
	else
		return;
	va_end(ap);
}
