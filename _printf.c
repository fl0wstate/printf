#include "main.h"
#include <unistd.h>

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
/**
 * digit_counter - counts the number of digits present
 * @num: digits passed
 * Return: number of digits present
 */
int digit_counter(int num)
{
	int temp = 0, count = 0;

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
 * _printf - simple replica of printf project.
 * @format: type of format specifier.
 * Return: length of the format.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int index_arr_no, i = 0;
	ssize_t count = 0;
	specifiers_x formats[] = {
		{'c', _char_arg},
		{'s', _string_arg},
		{'%', _percent_arg},
		{'d', _digit_arg},
		{'i', _digit_arg},
		{0, NULL}
	};

	if (!format)
		return (1);
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			index_arr_no = 0;
			i++;
			while (formats[index_arr_no].form_t)
			{
				if (format[i] == formats[index_arr_no].form_t)
				{
					count += formats[index_arr_no].call(&ap);
					break;
				}
				index_arr_no++;
			}
			if (!formats[index_arr_no].form_t)
				count += write(STDOUT_FILENO, &format[i], 1);
		}
		else
			count += write(STDOUT_FILENO, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
/* added some helper function but still room for other two function */
