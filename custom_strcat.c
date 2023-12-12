#include "simple_shell.h"

/**
 * custom_strcat - Concatenates two strings.
 * @destination: The destination string to concatenate to.
 * @source: The source string to append.
 *
 * This function appends the content of the source string to the destination
 * string, and ensures that the destination string is null-terminated.
 * The destination string must have enough space to accommodate both strings.
 *
 * Parameters:
 *   destination: A pointer to the destination string.
 *   source:      The source string to be appended.
 *
 * Return: A pointer to the destination string.
 */

char *custom_strcat(char *destination, const char *source)
{
	char *result = destination;

	while (*destination)
		destination++;

	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return (result);

}
