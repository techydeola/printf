#include "main.h"
/**
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
