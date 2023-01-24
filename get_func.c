#include "print.h"

/**
 * pick_func - select function to perform based
 * on inputed char
 * @ch: the character
 *
 * Return: pointer to function
 */

int (*pick_func(const char ch))(va_list)
{
	int i = 0;

	f_struct flg_arr[] = {
		{'i', print_number},
		{'d', print_number},
		{'c', _putchar}
		/*{'s', print_string},
		{'%', print_percentage}*/
	};

	while (i < 3)
	{
		if (ch == flg_arr[i].c)
			return (flg_arr[i].func);
		i++;
	}
	return (NULL);
}

/**
 * _printf - produce output according to a format
 * @format: the format
 *
 * Return: length of string
 */

int _printf(const char *format, ...)
{
	va_list fmt_var;
	int i = 0, len = 0;
	int (*ptr)(char c);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(fmt_var, format);

	while (format[i] != '\0')
	{
		if (*format == '%')
		{
			format++;

			ptr = pick_func(format);

		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(fmt_var);

	return (len);
}
