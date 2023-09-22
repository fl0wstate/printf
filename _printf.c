#include "main.h"
#include <unistd.h>

/**
 * _printf - simple replica of printf project.
 * @format: type of format specifier.
 * Return: length of the format.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int index_arr_no, i = 0;
	size_t count = 0;
	specifiers_x formats[] = {
		{'c', _char_arg}, {'s', _string_arg},
		{'%', _percent_arg}, {'d', _digit_arg},
		{'i', _digit_arg}, {'b', _binary_arg},
		{'o', _octal_arg}, {'x', _low_hex_arg},
		{'X', _upper_hex_arg}, {'R', _rot13_arg},
		{'u', _unsigned_args}, {'r', _reverse_arg},
		{'p', _pointer_hex_arg}, {'S', _no_printable_arg},
		{0, NULL}
	};
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			index_arr_no = 0;
			while (formats[index_arr_no].form_t)
			{
				if (format[i] == formats[index_arr_no].form_t)
				{
					count += formats[index_arr_no].call(&ap);
					break;
				}
				index_arr_no++;
			}
			if (formats[index_arr_no].form_t == 0)
				count += write(STDOUT_FILENO, &format[i], 1);
		}
		else
			count += write(STDOUT_FILENO, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}


/**
 * _reverse_arg - simple function that reverses a string
 * @ap: pointer to a list of indefinite number of arguments
 * Return: number of bytes written
 */
int _reverse_arg(va_list *ap)
{
	char *str, *retrive;
	int len = 0, i = 0, result;

	retrive = va_arg(*ap, char *);
	if (!retrive)
		return (0);

	len = _strlen(retrive);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		_puts("Memory allocation failed");
		return (0);
	}
	while (i < len)
	{
		str[i] = retrive[len - i - 1];
		i++;
	}
	str[i] = '\0';
	result = write_buffer(str);
	free(str);
	return (result);
}

/**
 * digit_counter - counts the number of digits present
 * @num: digits passed
 * Return: number of digits present
 */
unsigned int digit_counter(int num)
{
	unsigned int temp = 0, count = 0;

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
 * _abs - Entry point
 * @num: holding the int value to be converted into an absolute value
 * Return: void just returns the absolute value of the param passed
 */
unsigned long int _abs(long int num)
{
	if (num < 0)
	{
		num *= -1;
	}
	return (num);
}

/**
 * _percent_arg - handling the case of percent args
 * @ap: list of arguments passed
 * Return: number of written bytes
 */
int _percent_arg(va_list *ap)
{
	(void)ap;
	return (write(STDOUT_FILENO, "%", 1));
}
