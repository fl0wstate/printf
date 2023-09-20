#include "main.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * get_val_ULINT - return the value of converters
 * @n: integers
 * Return: len of the integers
 */
unsigned long int get_val_ULINT(unsigned long int n)
{
	char *buf;
	unsigned long int len = 0, i = 0, rev = 0;

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
	for (rev = i - 1; rev > 0; rev--)
	{
		write(STDOUT_FILENO, &buf[rev], 1);
	}
	len = i;
	free(buf);
	return (len);
}

/**
 * get_val_UINT - return the value of converters
 * @n: integers
 * Return: len of the integers
 */
unsigned int get_val_UINT(unsigned int n)
{
	char *buf;
	unsigned int len = 0, i = 0, rev = 0;

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
	for (rev = i - 1; rev > 0; rev--)
	{
		write(STDOUT_FILENO, &buf[rev], 1);
	}
	len = i;
	free(buf);
	return (len);
}
/**
 * write_buffer - prints out the value of a string
 * @s: pointer to a string of chars
 * Return: len of the string
 */

int write_buffer(char *s)
{
	unsigned int i = 0;

	if (!s)
	{
		write(1, "0", 1);
		return (0);
	}
	while (s[i])
	{
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * creat_heap_mem - creates a memory in the heap
 * @num: number of bytes to create the memory heap
 * Return: pointer to the newly created memory int heap
 */
char *creat_heap_mem(unsigned long int num)
{
	char *s;

	s = malloc(sizeof(char) * (num + 1));
	if (!s)
	{
		_puts("Memory allocation failed");
		return (0);
	}
	return (s);
}

/**
 * _isUINT - checking which characters are in lowercase and returns 1
 * @num: num passed
 * Return: 1 if true otherwise 0 if false
 */

bool _isUINT(unsigned long int num)
{
	return (num <= (unsigned long int)UINT_MAX);
}

