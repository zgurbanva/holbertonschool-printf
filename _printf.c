#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed
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
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}

