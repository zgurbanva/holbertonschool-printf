#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * _printf - simplified printf that handles %c, %s and %%
 * @format: format string
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);

	for (; format[i]; i++)
	{
		if (format[i] != '%')           /* ordinary char */
		{
			count += _putchar(format[i]);
			continue;
		}

		i++;                           /* now look at specifier */
		if (!format[i])                /* stray '%' at the end */
			return (-1);

		switch (format[i])
		{
		case 'c':
			count += _putchar(va_arg(ap, int));
			break;
		case 's':
			count += _puts(va_arg(ap, char *));
			break;
		case '%':
			count += _putchar('%');
			break;
		default:                       /* unknown specifier → print verbatim */
			count += _putchar('%');
			count += _putchar(format[i]);
			break;
		}
	}

	va_end(ap);
	return (count);
}
