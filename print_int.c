#include "main.h"

/** print_int - a function that prints an integer number
 * @num: number to be printed
 */

void print_int(int num)
{
	if (num != '\0')
	{
		if (num <= 9)
			_putchar(num + '0');
		else if (num >= 10 && num <= 99)
		{
			_putchar((num / 10) + '0');
			_putchar((num % 10) + '0');
		}
	}
}
