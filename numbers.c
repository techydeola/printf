#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_int - function that prints an integer
 * @a: passed integer
 *
 * Return: (i)
 */

int print_int(int a)
{
	int i = 0, exp = 1;
	int num = a;
	int n = a;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
		i++;
	}

	while (num / 10 != 0)
	{
		exp *= 10;
		num /= 10;
	}

	num = n;

	while (exp > 0)
	{
		int digit = num / exp;

		_putchar(digit + '0');
		num -= digit * exp;
		exp /= 10;
		i++;
	}

	i++;

	return (i);
}
