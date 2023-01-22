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
 * print_number - print integer numbers
 * @n: the integer to be printed
 *
 * Return: nothing
 */

void print_number(int n)		
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}

	if ((n / 10) != 0)
		print_number(n / 10);
	
	putchar(n % 10 + '0');
}
/**
 * print_unsigned_int - print only positive numbers
 * @n: the positive number
 *
 * Return: nothing
 */
void print_unsigned_int(unsigned int n)
{
	if ((n / 10) != 0)
		print_unsigned_int(n / 10);

	putchar(n % 10 + '0');
}
/**
 * _strlen - print the length of string to stdout
 * @s: the string
 *
 * Return: length in int
 */

int _strlen(char *s)
{
	int len = 0;
	if (*s == '0')
		return (0);
	len++;
	return (len + _strlen(s + len));
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
	int start, end, i = strlen(c), j;
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
		putchar(c[j]);
		j++;
	}
}
/**
 * print_hexadecimal - print hexadecimal
 * @n: the number
 * @c: uppercase or lowercase a
 *
 * Return: nothing
 */

void print_hexadecimal(unsigned int n,char flag)
{
	char hex_arr[15];
	int i = 0, start, end, j;	
	char temp;

	while (n > 0)
	{
		int remainder = n % 16;
		if (remainder < 10)
			hex_arr[i] = remainder + '0';
		else
			hex_arr[i] = remainder - 10 + flag;
		n /= 16;
		i++;
	}
	hex_arr[i] = '\0';

	str_reverse(hex_arr);
}
/**
 * print_upper_hexa - print number in uppercase
 * hexadecimal
 * @n: the number
 *
 * Return: void
 */
void print_upper_hexa(unsigned int n, char A)
{
	print_hexadecimal(n, A);
}
/**
 * print_lower_hexa - print number in lowercase
 * hexadecimal
 * @n: the number
 *
 * Return: void
 */
void print_lower_hexa(unsigned int n, char a)
{
	print_hexadecimal(n, a);
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
	fputs(s, stdout);
}
/*void print_address(void *ptr)
{
	fputs(ptr, stdout);
}*/
