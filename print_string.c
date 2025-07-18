#include <stddef.h>  /* For NULL */
#include <unistd.h>  /* For write */
#include "main.h"

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}

	return (count);
}
