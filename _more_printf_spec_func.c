#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _low_hex_arg - converts integers to hexadecimal numbers.
 * @ap: decimal number
 * Return: len of the array
 */

int _low_hex_arg(va_list *ap)
{
	unsigned long int decimal, rem = 0;
	int i = 0, j;
	char *hex, temp;

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
	return (i);
}

/**
 * _upper_hex_arg - converts integers to hexadecimal numbers.
 * @ap: decimal number
 * Return: len of the array
 */

int _upper_hex_arg(va_list *ap)
{
	unsigned long int decimal, rem = 0;
	int i = 0, j;
	char *hex, temp;

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
	return (i);
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

	if (digit == 0)
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

	long int num = va_arg(*ap, long int), temp = 0;
	char *binary;
	int len = 0, i = 0, n_bytes = 0;
	bool is_negative = false;

	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		num = -num;
		is_negative = true;
	}
	temp = num;
	while (temp > 0)
	{
		temp /= 2;
		len++;
	}
	binary = create_special_heap(len, is_negative);
	while (num > 0)
	{
		binary[i++] = num % 2 + '0';
		num /= 2;
	}
	if (is_negative)
		binary[i++] = '1';
	binary[i] = '\0';
	while (i > 0)
	{
		i--;
		write(STDOUT_FILENO, &binary[i], 1);
		n_bytes++;
	}
	free(binary);
	return (n_bytes);
}

/**
 * _rot13_arg - simple implementation of the rot13 theory
 * @ap: list of undefinite number of arguments
 * Return: number of bytes to be written
 */

int _rot13_arg(va_list *ap)
{
	char *s = va_arg(*ap, char *), c, *temp;
	unsigned int i = 0, len = 0;

	if (!s)
		return (write(1, "(null)", 1));

	len = _strlen(s);
	temp = creat_heap_mem(len);

	while (s[i] != '\0')
	{
		c = s[i];
		if ((c >= 'A' && c <= 'Z'))
		{
			if (c >= 'A' && c <= 'M')
			{
				temp[i] = c + 13;
			}
			else
				temp[i] = c - 13;
		}
		else if ((c >= 'a' && c <= 'z'))
		{
			if (c >= 'a' && c <= 'm')
				temp[i] = c + 13;
			else
				temp[i] = c - 13;
		}
		else
			temp[i] = c;
		i++;
	}
	temp[i] = '\0';
	i = write_buffer(temp);
	free(temp);
	return (i);
}
