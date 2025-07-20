#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @args: Unused
 * Return: Number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

