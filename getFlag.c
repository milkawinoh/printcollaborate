#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: The formatted string to print arguments in
 * @i: A pointer to the current index in the format string
 *
 * Returns: The active flags
 */
int get_flags(const char *format, int *i)
{
	/* The possible flag characters and their corresponding bit values */
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i, flags = 0;

	/* Loop through the format string starting from the current index */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a flag character */
		for (j = 0; FLAG_CHARS[j] != '\0'; j++)
			if (format[curr_i] == FLAG_CHARS[j])
			{
				/* Set the corresponding bit for the flag character */
				flags |= FLAG_VALUES[j];
				break;
			}

		/* If the current character is not a flag character, break out of the loop */
		if (FLAG_CHARS[j] == 0)
			break;
	}

	/* Update the current index to the last processed character */
	*i = curr_i - 1;

	return flags;
}

