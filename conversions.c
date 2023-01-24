#include "print.h"

/**
 * convert_base - convert number from base 10 to
 * ther bases
 * @nb: the number
 * @base: the parent base or base 10
 * @upper: check for upper case
 *
 * Return: the new base in string
 */
char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int i = 0;
	char *str;
	unsigned int nbr = nb;

	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';

	while (i >= 0)
	{
		nbr = nb % base;
		str[i] = convert_alpha_numeric(nbr, upper);
		nb /= base;
		i--;
	}
	return (str);
}
/**
 * print_octal - print number in octal number
 * @num: the number
 *
 * Return: nothing
 */

void print_octal(unsigned int num)
{
	char *arr;
	int i = 0;

	arr = malloc(sizeof(char) * (i + 1));

	while (num > 0)
	{
		int remainder = num % 8;

		arr[i] = remainder + '0';
		num /= 8;
		i++;
	}
	arr[i] = '\0';

	str_reverse(arr);
}

/**
 * print_hexadecimal - print hexadecimal
 * @n: the number
 * @flag: uppercase or lowercase a
 *
 * Return: nothing
 */
void print_hexadecimal(unsigned int n, char flag)
{
	int i = 0, start, end, j;
	char *hex_arr, temp;

	hex_arr = malloc(sizeof(char) * (i + 1));

	if (hex_arr == NULL)
		return;

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
	free(hex_arr);
}

/**
 * convert_alpha_numeric - convert alphabets to it's numeric value
 * @nb: the number
 * @upper: check for uppercase
 *
 * Return: its numerical value
 */
int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	else
		return (nb + '0');
}
