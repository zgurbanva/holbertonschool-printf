#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list with the character
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

