#include "main.h"

/**
 * handle_format - Dispatches format specifier
 * @format: The format specifier character
 * @args: List of arguments
 * Return: Number of characters printed
 */
int handle_format(char format, va_list args)
{
	switch (format)
	{
		case 'c': return print_char(args);
		case 's': return print_string(args);
		case '%': return print_percent(args);
		case 'd':
		case 'i': return print_int(args);
		default:
			write(1, "%", 1);
			write(1, &format, 1);
			return (2);
	}
}

