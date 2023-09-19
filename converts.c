#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _low_hex_arg - converts integers to hexadecimal numbers.
 * @ap: decimal number
 * Return: len of the array
 */

int _low_hex_arg(va_list *ap)
{
	unsigned long int rem = 0, i = 0, j, decimal = 0;
	char temp;
	char *hex;

	decimal = va_arg(*ap, unsigned int);
	if (decimal == 0)
		return (write(STDOUT_FILENO, "0", 1));

	hex = creat_heap_mem(digit_counter(decimal));
	while (decimal > 0)
	{
		rem = decimal % 16;
		if (rem < 10)
			hex[i++] = '0' + rem;
		else
			hex[i++] = 'a' + (rem - 10);
		decimal /= 16;
	}
	j = 0;
	for (; j < i / 2; j++)
	{
		temp = hex[j];
		hex[j] = hex[i - 1 - j];
		hex[i - 1 - j] = temp;
	}
	hex[i] = '\0';
	i = write_buffer(hex);
	free(hex);
	return ((unsigned long int)i);
}

/**
 * _upper_hex_arg - converts integers to hexadecimal numbers.
 * @ap: decimal number
 * Return: len of the array
 */

int _upper_hex_arg(va_list *ap)
{
	unsigned long int rem = 0, i = 0, j, decimal = 0;
	char temp;
	char *hex;

	decimal = va_arg(*ap, unsigned long int);

	if (decimal == 0)
		return (write(STDOUT_FILENO, "0", 1));
	hex = creat_heap_mem(digit_counter(decimal));
	while (decimal > 0)
	{
		rem = decimal % 16;
		if (rem < 10)
			hex[i++] = '0' + rem;
		else
			hex[i++] = 'A' + (rem - 10);
		decimal /= 16;
	}
	j = 0;
	for (; j < i / 2; j++)
	{
		temp = hex[j];
		hex[j] = hex[i - 1 - j];
		hex[i - 1 - j] = temp;
	}
	hex[i] = '\0';
	i = write_buffer(hex);
	free(hex);
	return ((unsigned long int)i);
}

/**
 * _octal_arg - converts integer to octal values
 * @ap: number to be converted
 * Return: 0 success
 */

int _octal_arg(va_list *ap)
{
	unsigned long int rem = 0, octal = 0, digit = 0;
	unsigned long int pos = 1;

	digit = va_arg(*ap, unsigned long int);

	if (decimal == 0)
		return (write(STDOUT_FILENO, "0", 1));
	while (digit > 0)
	{
		rem = digit % 8;
		digit /= 8;
		octal += (rem * pos);
		pos *= 10;
	}
	return (get_converters_val(octal));
}

/**
 * _binary_arg - simple c program for converting decimal to binary
 * @ap: placeholder for the passed function
 * Return: binary number
 */

int _binary_arg(va_list *ap)
{
	long int pos = 1, bin = 0, rem = 0, num = 0;

	num = va_arg(*ap, long int);
	if (decimal == 0)
		return (write(STDOUT_FILENO, "0", 1));
	while (num > 0)
	{
		rem = num % 2;
		num /= 2;
		bin += (rem * pos);
		pos *= 10;
	}
	return (get_converters_val(bin));
}

/**
 * _rot13_arg - simple implementation of the rot13 theory
 * @ap: list of undefinite number of arguments
 * Return: number of bytes to be written
 */

int _rot13_arg(va_list *ap)
{
	char *s = va_arg(*ap, char *);
	unsigned long int i = 0, m = 0;
	char c; /* store chars found in the string */

	if (!s)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		c = s[i];
		m = s[i] / 32; /* transforms char to int */
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			s[i] = ((m * 32) + 1) + ((s[i] - ((m * 32) + 1) + 13) % 26);
		}
		i++;
	}
	i = write_buffer(s);
	return (i);
}
