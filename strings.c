#include "print.h"

/**
 * _strlen - print the length of string to stdout
 * @s: the string
 *
 * Return: length in int
 */

int _strlen(char *s)
{
	int len = 0;

	if (*s == '\0')
		return (0);
	len++;
	return (len + _strlen(s + 1));
}
/**
 * str_reverse - Reverse string and print it to stdout
 *
 * @c: the string
 *
 * Return: reversed string
 */

void str_reverse(char *c)
{
	int start, end, i = _strlen(c), j;
	char temp;

	start = 0;
	end = i - 1;

	while (start < end)
	{
		temp = c[start];
		c[start] = c[end];
		c[end] = temp;
		start++;
		end--;
	}
	j = 0;
	while (c[j] != '\0')
	{
		_putchar(c[j]);
		j++;
	}
}
