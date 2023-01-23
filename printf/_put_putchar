#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes character to stdout
 * @c: the character
 * Return: 1 (success).
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints string to stdout
 * @str:  string to be printed
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
