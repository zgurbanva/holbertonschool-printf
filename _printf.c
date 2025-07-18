#include "main.h"

/**
 * print_char - prints a character
 * @args: arguments list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: arguments list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int count = 0;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

/**
 * handle_format - handles format specifier
 * @format: format character
 * @args: arguments list
 * Return: number of characters printed
 */
int handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_string(args));
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		return (2);
	}
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of chars printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			count += handle_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
