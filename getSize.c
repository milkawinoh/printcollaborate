#include "main.h"

/**
 * get_size - Determines the size to cast the argument based
 * on format specifier.
 * @format: A formatted string containing the arguments to be printed.
 * @index: A pointer to an integer representing the index of the current
 * character in the format string.
 * Return: An integer representing the size to cast the argument.
 */
int get_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = LONG_SIZE;
	else if (format[curr_index] == 'h')
		size = SHORT_SIZE;

	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;

	return (size);
}

