#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*The function my_putstr takes a pointer to a character array
*(i.e., a string) as its argument and returns an integer*/

int my_putstr(char *s);

/* The function my_putchar takes a single character c 
*as its argument and returns an integer.*/
int my_putchar(char c)
{
    return write(1, &c, 1);
}

/*The function nbr_put_point takes a 
*pointer val_p as its argument and returns an integer.*/
int nbr_put_point(void *val_p)
{
    void *pcase = val_p;
    int i = 0, hgt = 0;
    unsigned long min, put_h[64], ppoint;

    if (pcase == NULL) my_putstr("(null)");
    ppoint = (unsigned long)pcase;
    while (ppoint != 0)
    {
        min = ppoint % 16;
        if (min < 10)
            put_h[i] = min + 48;
        else
        {
            put_h[i] = min;
            put_h[i] = min + 87;
        }
        ppoint /= 16, i++;
    }
    hgt += my_putstr("0x");
    while (i - 1 >= 0)
    {
        my_putchar(put_h[i - 1]), i--, hgt++;
    }
    return (hgt);
}

/*The function my_putnbr_base takes an unsigned integer
*nbr, a character array base containing the digits of
*the desired base, and an integer base_size representing
*the number of digits in the base. The function returns 
*an integer, which is the number of characters that were
*printed to the standard output stream (i.e., the console).
*/
int my_putnbr_base(unsigned int nbr, char *base, int base_size)
{
    int count = 0;
    if (nbr >= (unsigned int)base_size)
    {
        count += my_putnbr_base(nbr / base_size, base, base_size);
    }
    count += my_putchar(base[nbr % base_size]);
    return count;
}

/*The function my_putnbr takes an integer nbr as its argument
*and returns an integer, which is the number of characters that
*were printed to the standard output stream (i.e., the console).
*/
int my_putnbr(int nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        count += my_putchar('-');
        nbr *= -1;
    }
    if (nbr / 10)
    {
        count += my_putnbr(nbr / 10);
    }
    count += my_putchar(nbr % 10 + '0');
    return count;
}
/**The function my_putstr takes a pointer to a character array
*(i.e., a string) as its argument and returns an integer, which
*is the length of the input string. 
*/
int my_putstr(char *s)
{
    int len = strlen(s);
    write(1, s, len);
    return len;
}

int my_printf(char *restrict format, ...)
{
    va_list args;
    va_start(args, format);
    int written = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                // %d: interprets the corresponding argument as
                // an integer and outputs it to the console using the my_putnbr function.
                case 'd':
                {
                    written += my_putnbr(va_arg(args, int));

                    break;
                }
                //%o: interprets the corresponding argument as an unsigned integer and
                // outputs it to the console in octal format using the my_putnbr_base function.
                case 'o':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += my_putnbr_base(i, "01234567", 8);
                    break;
                }
                //%u: interprets the corresponding argument as an unsigned integer and outputs
                // it to the console in decimal format using the my_putnbr_base function.
                case 'u':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += my_putnbr_base(i, "0123456789", 10);
                    break;
                }
                // %x: interprets the corresponding argument as an unsigned integer and outputs it
                // to the console in hexadecimal format using the my_putnbr_base function.
                case 'x':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += my_putnbr_base(i, "0123456789ABCDEF", 16);
                    break;
                }
                // %c: interprets the corresponding argument as a character and outputs it to the
                // console using the write system call.
                case 'c':
                {
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    written++;
                    break;
                }
                // %s: interprets the corresponding argument as a string and outputs it to the
                // console using the my_putstr function.
                case 's':
                {
                    char *s = va_arg(args, char *);
                    int cwritten = 0;
                    if (s == NULL)
                    {
                        cwritten = my_putstr("(null)");
                    }
                    else
                    {
                        cwritten = my_putstr(s);
                    }
                    written += cwritten;
                    break;
                }
                // %p: interprets the corresponding argument as a pointer and outputs its address to
                // the console using the nbr_put_point function.
                case 'p':
                {
                    void *p = va_arg(args, void *);
                    written += nbr_put_point(p);

                    break;
                }
               
                default:
                {
                    char c = *format;
                    write(1, &c, 1);
                    written++;
                    break;
                }
            }
        }
         // If the format specifier is not recognized, the function simply outputs the
        //  corresponding literal character to the console.
        else
        {
            written += my_putchar(format[i]);
        }
    }
    // The function returns the total number of characters written to the console, which
    // includes both the format specifier output and the literal characters output.
    return written;
}


