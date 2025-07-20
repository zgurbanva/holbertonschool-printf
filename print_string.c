#include "main.h"

/**
 * print_string - Prints a string
 * @args: va_list with the string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "(null)";

	while (str[len])
		len++;

	return (write(1, str, len));
}

