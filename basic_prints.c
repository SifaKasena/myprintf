#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @n: integer pointer
 * Return: void
 */

void print_char(unsigned int *n, ...)
{
	va_list ptr;
	char c;

	va_start(ptr, n);
	c = va_arg(ptr, int);
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_int - prints an integer
 * @n: integer pointer
 * Return: void
 */

void print_int(unsigned int *n, ...)
{
	va_list ptr;
	int num;
	char c;
	unsigned int u_num;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num < 0)
	{
		c = '-';
		write(1, &c, 1);
		u_num = -num;
	}
	else
	{
		u_num = num;
	}
	if (u_num / 10)
		print_int(n, u_num / 10);
	c = u_num % 10 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_str - prints a character string
 * @n: integer pointer
 * Return: void
 */

void print_str(unsigned int *n, ...)
{
	va_list ptr;
	char *s;

	va_start(ptr, n);
	s = va_arg(ptr, char *);
	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		write(1, s, 1);
		(*n)++;
		s++;
	}
	va_end(ptr);
}
