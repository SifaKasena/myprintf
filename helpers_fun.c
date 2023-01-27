#include "main.h"

/**
 * get_type - selects the type of variable expected
 * @c: modifier
 * Return: integer
 */

int get_type(char c)
{
	char ints[] = {'c', 'd', 'i', 'b', 'u', 'o', 'x', 'X'};
	char *str = "spSrR";
	int i, bool_int, bool_str;

	bool_int = bool_str = 0;
	for (i = 0; i < 8; i++)
	{
		if (ints[i] == c)
		{
			bool_int = 1;
			break;
		}
	}
	for (i = 0; i < 5; i++)
	{
		if (str[i] == c)
		{
			bool_str = 1;
			break;
		}
	}
	if (bool_int)
		return (1);
	else if (bool_str)
		return (2);
	else if (c == '%')
		return (0);
	return (4);
}

/**
 * get_mod_fun - gets the correct function to call
 * @c: charcter to check
 * Return: pointer to corresponding function
 */

void (*get_mod_fun(char c))(unsigned int *n, ...)
{
	mod_fun mods[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin},
		{'u', print_uint},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_hex_caps},
		{'p', print_adr},
		{'S', print_str_hex},
		{'r', print_rev},
		{'R', print_rot13}
	};
	unsigned int i = 0;

	while (mods[i].mod != c)
		i++;

	return (mods[i].fun);
}
