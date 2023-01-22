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
	va_start(arg, format);
	char a = 'a', A = 'A';
	int len = 0;
	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch(*format)
			{
				case 'c':
					putchar(va_arg(arg, int));
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
					print_unsigned_int(va_arg(arg,unsigned int));
					break;
				case 'x':
					print_lower_hexa(va_arg(arg, unsigned int), a);
					break;
				case 'X':
					print_upper_hexa(va_arg(arg, unsigned int), A);
					break;
				case '%':
					putchar('%');
					break;
				/*case 'p':
					print_address(va_arg(arg, void*));
					break;*/
			}
		}
		else
			putchar(*format);
		format++;
		len += 1;
	}
	va_end(arg);

	return (len);
}
