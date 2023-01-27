#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - custom printf function
 * @format: charcter string composed of 0 or more directives of
 * what _printf should print
 * Return: number of bytes printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	unsigned int n, i, type;
	va_list ptr;

	n = i = 0;
	va_start(ptr, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			n++;
		}
		else
		{
			if (format[++i] == '\0')
				return (-1);
			type = get_type(format[i]);
			switch (type)
			{
				case 0:
					write(1, format + i, 1);
					n++;
					break;
				case 1:
					get_mod_fun(format[i])(&n, va_arg(ptr, long));
					break;
				case 2:
					get_mod_fun(format[i])(&n, va_arg(ptr, void *));
					break;
				default:
					write(1, format + i - 1, 2);
					n += 2;
					break;
			}
		}
		i++;
	}
	va_end(ptr);
	return (n);
}
