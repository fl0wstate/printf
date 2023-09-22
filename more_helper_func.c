#include "main.h"
#include <unistd.h>

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
		return (NULL);
	}
	return (s);
}

/**
 * digit_long_counter - counts the number of digits present in
 * a long int
 * @num: digits passed
 * Return: number of digits present
 */
unsigned long int digit_long_counter(unsigned long int num)
{
	unsigned long int temp = 0, count = 0;

	temp = num;
	count = (temp == 0) ? 1 : 0;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

/**
 * _puts - output the strings to the stdio
 * @s: pointer to a string of chars
 * Return: void
 */
void _puts(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		write(STDOUT_FILENO, &s[i], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * _strlen - get the length of a string
 * @s: pointer to a string of chars
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] && s)
		len++;
	return (len);
}
