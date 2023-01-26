#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_bin - prints a number in binary form
 * @n: integer pointer
 * Return: void
 */

void print_bin(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 2)
		print_bin(n, num / 2);
	c = num % 2 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_str_hex - prints a character string where non printable charcters
 * are printed in \x format followed by its hexadecimal value in uppercase
 * @n: integer pointer
 * Return: void
 */

void print_str_hex(unsigned int *n, ...)
{
	va_list ptr;
	char hex[] = {'\\', 'x'};
	char *s, c = '0';

	va_start(ptr, n);
	s = va_arg(ptr, char *);
	while (*s != '\0')
	{
		if ((*s < 32 && *s > 0) || *s >= 127)
		{
			write(1, hex, 2);
			if (*s < 16)
				write(1, &c, 1);
			print_hex_caps(n, *s);
		}
		else
		{
			write(1, s, 1);
			(*n)++;
		}
		s++;
	}
	va_end(ptr);
}
