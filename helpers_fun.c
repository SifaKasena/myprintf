#include "main.h"

/**
 * get_type - selects the type of variable expected
 * @c: modifier
 * Return: integer
 */

int get_type(char c)
{
	char ints[] = {'c', 'd', 'i', 'b', 'u', 'o', 'x', 'X'};
	int i, state = 0;

	for (i = 0; i < 8; i++)
	{
		if (ints[i] == c)
		{
			state = 1;
			break;
		}
	}
	if (state)
		return (1);
	else if (c == 's' || c == 'p' || c == 'S')
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
		{'S', print_str_hex}
	};
	unsigned int i = 0;

	while (mods[i].mod != c)
		i++;

	return (mods[i].fun);
}
