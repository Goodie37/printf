#include "main.h"
#include <stdlib.h>
#include "stdarg.h"

/**
 * print_specifier - selects and calls the corresponding conversion function
 *	       according to the conversion specifier.
 * @format: the conversion specifier character.
 * @args: the va_list of arguments for the conversion.
 *
 * Return: the number of characters printed.
 */
int print_specifier(char format, va_list args)
{
	int i = 0, len = 0;
	conv_spec conversions[] = {
	    {"c", print_char},
	    {"s", print_str},
	    {"d", print_int},
	    {"i", print_int},
	    {"b", print_int_b},
	    {"u", print_uint},
	    {"o", print_octal},
	    {"x", print_hex},
	    {"X", print_hex_upper},
	    {"S", print_custom_str},
	    {"p", print_pointer},
	    {"r", print_revstr},
	    {"R", print_rot13},
	    {NULL, NULL}};

	while (conversions[i].spec)
	{
		if (*conversions[i].spec == format)
			len = conversions[i].func(args);
		i++;
	}

	return (len);
}
