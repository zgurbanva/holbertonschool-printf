#include <unistd.h> 
#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list containing the char
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

