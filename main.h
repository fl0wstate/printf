#ifndef _MAIN_H
#define _MAIN_H

/* Custom header files */
#include <stdarg.h>
#include <string.h>
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
int fill_no_printable_buff(unsigned int n, char *new_buf, char *old_buf);
void _get_base(unsigned int num, unsigned int base, char *buff);
unsigned long int digit_long_counter(unsigned long int num);
unsigned long int get_converters_val(unsigned long int n);
unsigned long int get_val_ULINT(unsigned long int n);
int base_len(unsigned int num, unsigned int base);
char *create_special_heap(int num, bool sign);
char *creat_heap_mem(unsigned long int num);
unsigned int get_val_UINT(unsigned int n);
int _printf(const char *format, ...);
unsigned long int _abs(long int num);
unsigned int digit_counter(int num);
bool _isUINT(unsigned long int num);
char *get_hex_val(unsigned int dec);
int _no_printable_arg(va_list *ap);
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
bool _is_printable(char ch);
void _swap_func(char *str);
int _rot13_arg(va_list *ap);
int _char_arg(va_list *ap);
int write_buffer(char *s);
int _strlen(char *s);
void _puts(char *s);

#endif
