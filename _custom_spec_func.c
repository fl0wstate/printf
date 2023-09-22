#include "main.h"
#include <stdarg.h>

/**
 * _no_printable_arg - prints out _no_printable_arg into hex_uppercase
 * @ap: list of the indefinite number of arguments
 *
 * Return: 0 success, 1 failure
 */
int _no_printable_arg(va_list *ap)
{
	char *str = NULL, *data = NULL;
	unsigned int i = 0, len = 0, ret = 0;

	str = va_arg(*ap, char *);
	if (!str)
	{
		_puts("No string passed");
		return (0);
	}

	while (str[i])
	{
		if (!_is_printable(str[i]))
			len += 4; /* non_printable len */
		else
			len++;/* add space for the printable */
		i++;
	}
	i = 0;
	data = creat_heap_mem(len);
	if (!fill_no_printable_buff(len, data, str))
	{
		free(data); /* ooh fatal crash */
		free(str);
		return (0);
	}
	ret = write_buffer(data); /* success */
	free(data);
	return (ret);
}

/**
 * fill_no_printable_buff - transforms all the non_printable chars to
 * hex_uppercase.
 * @n: number of bytes to write to the new buf
 * @new_buf: new buf to write to the transformed non_printable chars
 * @old_buf: Holds the string containing non_printable chars
 *
 * need another buffer to store the hex_uppercase char
 * write them to the new buff
 * prefix the new_buf with `\\` & `x`
 * once done add the rest of the characters as they were
 * return the new buff and don't forget to add the '\0'
 *
 * Return: 1 success(true), 0 failure(false)
 */
int fill_no_printable_buff(unsigned int n, char *new_buf, char *old_buf)
{
	char *hex_buff = NULL;
	unsigned int i = 0, j = 0;

	/* begin to write the chars to new buff */
	while (i < n)
	{
		if (!_is_printable(old_buf[j]) && old_buf[j] > 0)
		{
			hex_buff = get_hex_val((unsigned int)old_buf[j]);
			if (!hex_buff)
				return (0);
			new_buf[i++] = '\\';
			new_buf[i++] = 'x';
			if (hex_buff[1])
			{
				new_buf[i++] = hex_buff[0];
				new_buf[i++] = hex_buff[1];
			}
			else
			{
				new_buf[i++] = '0';
				new_buf[i++] = hex_buff[0];
			}
			free(hex_buff);
		}
		else
		{
			new_buf[i] = old_buf[j];
			i++;
		}
		j++;
	}
	new_buf[n] = '\0';
	return (1);
}

/**
 * _is_printable - function checks whether the char are printable or not
 * @ch: single character passed
 * Return: true success, false failure
 */
bool _is_printable(char ch)
{
	return ((ch >= 32 && ch < 127) ? 1 : 0);
}

/**
 * _swap_func - returns the reverse order of a given string
 * @str: pointer to a string of chars to be reversed
 * Return: pointer to the reserved string
 */
void _swap_func(char *str)
{
	char temp;
	unsigned int i = 0, j = 0;

	i = _strlen(str);
	for (; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - 1 - j];
		str[i - 1 - j] = temp;
	}
	str[i] = '\0';
}
