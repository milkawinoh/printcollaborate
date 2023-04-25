#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: The formatted string to print arguments in
 * @i: A pointer to the current index in the format string
 * @list: The list of arguments
 *
 * Return: The precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	/* Initialize variables */
	int curr_i = *i + 1; /* Current index in format string */
	int print_precision = -1; /* Precision value to be returned */

	/* If the next character is not '.', there is no precision */
	if (format[curr_i] != '.')
		return (print_precision);

	/* Initialize the precision to 0 */
	print_precision = 0;

	/* Loop through the format string starting from the character after '.' */
	for (curr_i = *i + 2; format[curr_i] != '\0'; curr_i++)
	{
		/* If the current character is a digit, add it to the precision */
		if (is_digit(format[curr_i]))
		{
			print_precision *= 10;
			print_precision += format[curr_i] - '0';
		}
		/* If the current character is '*', get the precision from the argument list */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			print_precision = va_arg(list, int);
			break;
		}
		/* If the current character is not a digit or '*', break out of the loop */
		else
			break;
	}

	/* Update the current index to the last processed character */
	*i = curr_i - 1;

	/* Return the precision */
	return (print_precision);
}

