#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing characters and conversion specifiers.
 *
 * Return: Number of characters printed (excluding the null byte).
 *         Returns -1 if format is NULL or in case of error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				if (write(1, &c, 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					if (write(1, str, 1) != 1)
					{
						va_end(args);
						return (-1);
					}
					str++;
					count++;
				}
			}
			else if (format[i] == '%')
			{
				if (write(1, "%", 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count++;
			}
			else
			{
				/* Handle unknown specifiers by printing '%' and the char */
				if (write(1, "%", 1) != 1 || write(1, &format[i], 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count += 2;
			}
		}
		else
		{
			if (write(1, &format[i], 1) != 1)
			{
				va_end(args);
				return (-1);
			}
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
