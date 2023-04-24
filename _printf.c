#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A function that prints formatted output.
 * @format: A character string containing format specifications.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	/* Declare and initialize necessary variables */
	int i, printed_chars = 0, total_printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list arg_list;
	char output_buffer[BUFF_SIZE];

	/* Check if the format string is NULL */
	if (format == NULL)
		return (-1);

	/* Initialize variable arguments list */
	va_start(arg_list, format);

	/* Iterate over the format string and print characters */
	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* If the character is not a format specifier, print it */
		if (format[i] != '%')
		{
			output_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(output_buffer, &buffer_index);
			total_printed_chars++;
		}
		/* If the character is a format specifier,
		   handle it accordingly */
		else
		{
			print_buffer(output_buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, arg_list);
			precision = get_precision(format, &i, arg_list);
			size = get_size(format, &i);
			++i;
			printed_chars = handle_print(format, &i, arg_list,
					output_buffer,
				flags, width, precision, size);
			if (printed_chars == -1)
				return (-1);
			total_printed_chars += printed_chars;
		}
	}

	/* Print the remaining characters in the output buffer */
	print_buffer(output_buffer, &buffer_index);

	/* Clean up variable arguments list */
	va_end(arg_list);

	/* Return the total number of characters printed */
	return (total_printed_chars);
}

/**
 * print_buffer - Prints the contents of the output buffer if it exists
 * @buffer: An array of characters
 * @buff_ind: A pointer to an integer representing the output buffer length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

