#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a single character
 * @args: va_list containing the character
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}
