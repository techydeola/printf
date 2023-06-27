#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int _putchar(char c);
void print_char(char ch);
void print_string(char *str);
void handle_other(const char *format, va_list ap);
int numbers(const char *format, ...);
void print_int(int a);
#endif
