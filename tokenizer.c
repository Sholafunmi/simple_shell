#include "shell.h"

/**
 * strtok_len - calculates the length of the first token in a string
 * @str: string
 * @delim: delimeter.
 * Return: integer
 */

int strtok_len(char *str, char *delim)
{
	int i = 0, length = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		length++;
		i++;

	}

	return (length);
}

/**
 * count_tokens - counts the number of tokens in a string
 * @str: string
 * @delim: delimiter
 * Return: integer
 */
int count_tokens(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += strtok_len(str + index, delim);
		}
	}

	return (tokens);
}
