#ifndef _MAIN_H
#define _MAIN_H

/* Custom header files */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * struct format_specifiers - simple char to function
 * data structure.
 * @form_t: means format type passed
 * @call: function associated with the char passed
 *
 * Description: Simple data structure which is used to
 * show the relationship between a char passed and
 * function it relates to.
 */
typedef struct format_specifiers
{
	char form_t;
	int (*call)(va_list *);
} specifiers_x;

/* Function prototypes */
unsigned long int digit_long_counter(unsigned long int num);
unsigned long int get_converters_val(unsigned long int n);
unsigned long int get_val_ULINT(unsigned long int n);
char *create_special_heap(int num, bool sign);
char *creat_heap_mem(unsigned long int num);
unsigned int get_val_UINT(unsigned int n);
int _printf(const char *format, ...);
unsigned long int _abs(long int num);
unsigned int digit_counter(int num);
bool _isUINT(unsigned long int num);
int _pointer_hex_arg(va_list *ap);
int _upper_hex_arg(va_list *ap);
int _unsigned_args(va_list *ap);
int _percent_arg(va_list *ap);
int _low_hex_arg(va_list *ap);
int _reverse_arg(va_list *ap);
int _binary_arg(va_list *ap);
int _string_arg(va_list *ap);
int _digit_arg(va_list *ap);
int _octal_arg(va_list *ap);
int _rot13_arg(va_list *ap);
int _char_arg(va_list *ap);
int write_buffer(char *s);
int _strlen(char *s);
void _puts(char *s);

#endif
