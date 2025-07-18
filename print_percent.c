#include <unistd.h>  /* For write */
#include "main.h"

/**
 * print_percent - Prints a percent sign
 * Return: 1
 */
int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
