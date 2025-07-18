#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("Hello %s! This is char: %c, and percent: %%\n", "Zeynab", 'Z');
	len2 = printf("Hello %s! This is char: %c, and percent: %%\n", "Zeynab", 'Z');

	_printf("Custom _printf length: %d\n", len1);
	printf("Standard printf length: %d\n", len2);

	return (0);
}
