#include "simple_shell.h"

/**
 * custom_strcpy - This copies a string.
 * @dest: The destination buffer to copy to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination buffer.
 */

char *custom_strcpy(char *dest, const char *src)
{
	char *destination = dest;

	while
		(
			(*destination++ = *src++)
			!= '\0');

	return (dest);
}
