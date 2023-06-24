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
		int num = va_arg(ap, int);
		int i, size = sizeof(int) * 8;
		int bit;
		unsigned int mask = 1U << (size - 1);
		int flag = 0;

		for (i = 0; i < size; i++)
		{
			bit = (num & mask) ? 1 : 0;
			if (bit || flag)
			{
				_putchar('0' + bit);
				flag = 1;
			}
			mask >>= 1;
		}
		if (!flag)
			_putchar('0');
	}
}
