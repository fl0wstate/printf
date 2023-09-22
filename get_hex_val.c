#include "main.h"
#include <unistd.h>

/**
 * get_hex_val - transforms a char to a hexadecimal val
 * @dec: decimal value of the char
 * Return: char datatype of the hexadecimal val
 */
char *get_hex_val(unsigned int dec)
{
	char *dec_holder = NULL;

	if (dec == 0)
	{
		_puts("Cannot store zero bytes");
		return (NULL);
	}
	dec_holder = creat_heap_mem(base_len(dec, 16));
	/* check here again in-case of memory leaks */
	_get_base(dec, 16, dec_holder);
	return (dec_holder);
}

/**
 * _get_base - return the base value of a given number
 * @num: number value
 * @base: base value
 * @buff: buffer to write to
 * return: void
 */
void _get_base(unsigned int num, unsigned int base, char *buff)
{
	unsigned int rem = 0, i = 0;

	while (num > 0)
	{
		rem = num % base;
		if (rem < 10)
			buff[i++] = '0' + rem;
		else
			buff[i++] = 'a' + (rem - 10);
		num /= base;
	}
	_swap_func(buff);
}

/**
 * base_len - get the len of a given base value
 * @num: number to get the length
 * @base: base type.
 * Return: malloc len to use
 */
int base_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
