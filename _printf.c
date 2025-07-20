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
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += print_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_integer(args);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
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

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return (len);
}

int print_percent(void)
{
	return (write(1, "%", 1));
}

int print_integer(va_list args)
{
	int n = va_arg(args, int);
	char buf[12];
	int i = 0, count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;

	do {
		buf[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);

	while (i--)
		count += write(1, &buf[i], 1);

	return (count);
}
