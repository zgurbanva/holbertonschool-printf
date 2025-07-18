#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

int print_string(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

int print_percent(void)
{
	return (_putchar('%'));
}

int print_integer(va_list args)
{
	int n = va_arg(args, int), div = 1, count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	while (num / div > 9)
		div *= 10;

	while (div)
	{
		count += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (count);
}

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
			switch (format[i])
			{
			case 'c':
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case '%':
				count += print_percent();
				break;
			case 'd':
			case 'i':
				count += print_integer(args);
				break;
			default:
				count += _putchar('%');
				count += _putchar(format[i]);
				break;
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
