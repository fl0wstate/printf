#include "main.h"
#include <unistd.h>

/**
 * _digit_arg - prints a digits format type
 * @ap: list of indefinite arguments number
 * Return: 0 (success)
 */
int _digit_arg(va_list *ap)
{
	int num, n_bytes = 0, elm = 0, digits = 0;
	bool negative_no = false;
	char *heap_no;

	num = va_arg(*ap, int);
	if (num == 0)
		return ((unsigned int)(write(STDOUT_FILENO, "0", 1)));
	if (num < 0)
	{/* set flag */
		negative_no = true;
		num = -num; /* remove the sign symbol for easy working with the digit */
	}
	digits = digit_counter(num);
	/* create space to store it */
	heap_no = malloc(sizeof(char) * (digits + (negative_no ? 1 : 0) + 1));
	if (!heap_no)
	{
		_puts("Memory allocation failed");
		return (-1);
	}
	while (num > 0)
	{ /* store each digit */
		heap_no[elm] = num % 10 + '0';
		num /= 10;
		elm++;
	}
	if (negative_no) /* add the sign symbol if is negative */
		heap_no[elm++] = '-';
	heap_no[elm] = '\0';
	while (elm > 0) /* flip it back to their right position */
	{
		elm--;
		/* get each element(digit) in position */
		write(STDOUT_FILENO, &heap_no[elm], 1);
		n_bytes++;
	}
	free(heap_no);
	return (n_bytes);
}

/**
 * _pointer_hex_arg - returns hexadecimal numbers which represent the memory
 * memory address of a given pointer or variable.
 * @ap: decimal number
 * Return: len of the array
 */
int _pointer_hex_arg(va_list *ap)
{
	unsigned long int decimal, rem = 0;
	int i = 0, j;
	char *hex, temp;

	decimal = va_arg(*ap, unsigned long int);

	if (decimal == 0)
		return (write(STDOUT_FILENO, "(nil)", _strlen("(nil)")));

	hex = creat_heap_mem(digit_long_counter(decimal) + 3);

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
	/* prefix values */
	hex[i++] = 'x';
	hex[i++] = '0';
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
 * _string_arg - prints a string format type
 * @ap: list of indefinite arguments number
 * Return: 0 (success)
 */
int _string_arg(va_list *ap)
{
	char *s;

	s = va_arg(*ap, char *);
	if (!s)
	{
		s = "(null)";
	}
	return ((unsigned int)(write(STDOUT_FILENO, s, _strlen(s))));
}
/**
 * _char_arg - prints a char format type
 * @ap: list of indefinite arguments number
 * Return: 0 (success)
 */
int _char_arg(va_list *ap)
{
	char x;

	x = va_arg(*ap, int);
	return ((unsigned int)(write(STDOUT_FILENO, &x, 1)));
}

