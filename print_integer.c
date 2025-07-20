#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: va_list with the integer
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int num = n, div = 1, count = 0;
	char digit;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}

	while ((num / div) >= 10)
		div *= 10;

	while (div)
	{
		digit = (num / div) + '0';
		count += write(1, &digit, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}

