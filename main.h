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
int _printf(const char *format, ...);
int _string_arg(va_list *ap);
int _char_arg(va_list *ap);
int _digit_arg(va_list *ap);
int digit_counter(int num);
int _strlen(char *s);
void _puts(char *s);
int _atoi(char *s);

/* Simple precise header file all the function mentioned here correlate */
#endif
