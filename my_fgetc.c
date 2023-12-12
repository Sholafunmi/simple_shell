#include "simple_shell.h"


/**
 * custom_fgetc - Reads a character from a file stream.
 * @stream: This file stream to read from.
 *
 * Return: The character read, or EOF if the end of file is reached or an error occurs.
 */

int custom_fgetc(FILE *stream)
{
	if (stream == NULL)
		return (EOF);

	int c = getc(stream);

	if (c == EOF)
		if (feof(stream))
			printf("End of file reached.\n");
		else if (ferror(stream))
			perror("Error reading from file");

	return (c);
}
