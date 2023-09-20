#include "main.h"
#include <unistd.h>
/**
 * _strlen - get the length of a string
 * @s: pointer to a string of chars
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
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
