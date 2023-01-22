#ifndef _PRINTF_
#define _PRINTF_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_number(int n);
void str_reverse(char *c);
void print_hexadecimal(unsigned int n, char flag);
void print_upper_hexa(unsigned int n, char A);
void print_lower_hexa(unsigned int n, char a);
void print_string(char *s);
void print_unsigned_int(unsigned int n);
void print_address(void *ptr);

#endif
