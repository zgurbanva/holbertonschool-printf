#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

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
            if (format[i] == 'c')
                count += print_char(args);
            else if (format[i] == 's')
                count += print_string(args);
            else if (format[i] == '%')
                count += print_percent();
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

/**
 * print_char - prints a character
 * @args: va_list
 * Return: 1
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);

    write(1, &c, 1);
    return (1);
}

/**
 * print_string - prints a string
 * @args: va_list
 * Return: number of chars printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

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
 * print_percent - prints a percent sign
 * Return: 1
 */
int print_percent(void)
{
    write(1, "%", 1);
    return (1);
}

