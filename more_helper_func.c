#include "main.h"
#include <unistd.h>
/**
 * _unsigned_args - return an absolute value given
 * @ap: list of indefinite number of arguments
 * Return: number of bytes written
 */
int _unsigned_args(va_list *ap)
{
	long int digit = 0;
	unsigned long int copy;
	unsigned int unintVal;

	digit = va_arg(*ap, long int);

	if (digit == 0)
		return (write(1, "0", 1));

	digit = _abs(digit);

	copy = (unsigned long int)digit;
	if (_isUINT(copy))
	{
		unintVal = (unsigned int)copy;
		return (get_val_UINT(unintVal));
	}
	else
	{
		return (get_val_ULINT(copy));
	}
}
/**
 * get_converters_val - return the value of converters
 * @n: integers
 * Return: len of the integers
 */
unsigned long int get_converters_val(unsigned long int n)
{
	char *buf;
	long int len = 0, i = 0;
	long int rev = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (-1);
	}
	buf = malloc(sizeof(char) * (digit_counter(n) + 1));
	if (!buf)
	{
		_puts("Memory allocation failed\n");
		return (-1);
	}
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	for (rev = i - 1; rev >= 0; rev--)
	{
		write(STDOUT_FILENO, &buf[rev], 1);
	}
	len = i;
	free(buf);
	return (len);
}

/**
 * create_special_heap - creates a memory in the heap
 * according to their sign value
 * @num: number of bytes to create the memory heap
 * @sign: determines the space for sign symbol
 * Return: pointer to the newly created memory int heap
 */
char *create_special_heap(int num, bool sign)
{
	char *s;

	s = malloc(sizeof(char) * (num + ((sign) ? 1 : 0) + 1));
	if (!s)
	{
		_puts("Memory allocation failed");
		return (0);
	}
	return (s);
}
