#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char ch);
int print_string(char *str);
void handle_other(const char *format, va_list ap);
int numbers(const char *format, ...);
int print_int(int a);
int _strlen(char *s); 
#endif
