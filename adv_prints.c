#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_uint - prints an unsigned integer
 * @n: integer pointer
 * Return: void
 */
void print_uint(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 10)
		print_uint(n, num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_oct - prints an integer in octal
 * @n: integer pointer
 * Return: void
 */
void print_oct(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 8)
		print_oct(n, num / 8);
	c = num % 8 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_hex - prints an integer in lower case hexadecimal
 * @n: integer pointer
 * Return: void
 */
void print_hex(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 16)
		print_hex(n, num / 16);
	c = num % 16 < 10 ? num % 16 + '0' : num % 16 + 87;
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_hex_caps - prints an integer in upper case hexadecimal
 * @n: integer pointer
 * Return: void
 */
void print_hex_caps(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 16)
		print_hex_caps(n, num / 16);
	c = num % 16 < 10 ? num % 16 + '0' : num % 16 + 55;
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_adr - prints an address
 * @n: integer pointer
 * Return: void
 */
void print_adr(unsigned int *n, ...)
{
	va_list ptr;
	unsigned long num;
	char c, *hex = "0x";

	va_start(ptr, n);
	num = va_arg(ptr, long);
	if (num / 16)
	{
		print_adr(n, num / 16);
	}
	else if (num == 0)
	{
		hex = "(nil)";
		print_str(n, hex);
	}
	else
	{
		write(1, hex, 2);
		*n += 2;
	}
	c = num % 16 < 9 ? num % 16 + '0' : num % 16 + 87;
	if (num != 0)
	{
		write(1, &c, 1);
		(*n)++;
	}
	va_end(ptr);
}
