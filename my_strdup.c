#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * custom_strdup - This duplicates a string.
 * @source: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */


char *custom_strdup(const char *source)
{
	if (source == NULL)
		return (NULL);

	size_t length = strlen(source);
	char *destination = (char *)malloc(length + 1);

	if (destination == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	strcpy(destination, source);

	return (destination);
}
