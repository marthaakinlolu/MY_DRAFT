#include "print.h"

/**
 * _putchar - print character to stdout
 * @c: the character
 *
 * Return: 1 if successful
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - write string to stdout
 * @str: string to print
 *
 * Return: number of printed char
 */
int _puts(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		counter++;
		str++;
	}
	return (counter);
}
