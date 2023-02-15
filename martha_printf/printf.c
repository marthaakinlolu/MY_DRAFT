#include "print.h"

/**
 * _printf - produce output according to a format
 * @format: the format
 *
 * Return: 1 if successful
 */

int _printf(const char *format, ...)
{
	va_list arg;
	char a = 'a', A = 'A';
	int len = 0;

	va_start(arg, format);


	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(arg, int));
					break;
				case 's':
					print_string(va_arg(arg, char *));
					break;
				case 'i':
					print_number(va_arg(arg, int));
					break;
				case 'd':
					print_number(va_arg(arg, int));
					break;
				case 'u':
					print_unsigned_int(va_arg(arg, unsigned int));
					break;
				case 'x':
					print_hexadecimal(va_arg(arg, unsigned int), a);
					break;
				case 'X':
					print_hexadecimal(va_arg(arg, unsigned int), A);
					break;
				case '%':
					_putchar('%');
					break;
				case 'o':
					print_octal(va_arg(arg, unsigned int));
					break;
				default:
					_putchar('%');
					_putchar(*format);
					break;
				}

		}
		else
			_putchar(*format);
		format++;
		len += 1;
	}
	va_end(arg);

	return (len);
}
