#include "print.h"

/**
 * print_number - print integer numbers
 * @n: the integer to be printed
 *
 * Return: nothing
 */

void print_number(int n)
{
	/*int n = va_arg(arg, int);*/

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if ((n / 10) != 0)
		print_number(n / 10);
	_putchar(n % 10 + '0');
}

/**
 * print_unsigned_int - print only positive numbers
 * @n: the positive number
 *
 * Return: nothing
 */

void print_unsigned_int(unsigned int n)
{
	/*int n = va_arg(arg, unsigned int);*/

	if ((n / 10) != 0)
		print_unsigned_int(n / 10);

	_putchar(n % 10 + '0');
}

/**
 * print_string - print string without
 * the new line character
 * @s: the string
 *
 * Return: nothing
 */

void print_string(char *s)
{
	int i = 0;
	char *str;

	str = malloc(sizeof(char) * _strlen(s) + 1);

	if (str == NULL)
		return;

	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';

	_puts(str);

	free(str);
}
