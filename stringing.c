#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 * Return: The length of the character string.
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;


	return (len);
}

/**
 * _strcpy - Copies two strings
 * @dest: destination
 * @src: source.
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i, j, k;


	j = 0;
	i = 0;
	while (src[i])
	{
		j++;
		i++;
	}
	
	k = 0;
	while (k < i)
	{
		dest[k] = src[k];
		k++;
	}


	dest[i] = '\0';
	return (dest);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */

char *_strchr(char *s, char c)
{
	int j;

	for (j = 0; s[j]; j++)
	{
		if (s[j] == c)
		{
		
			return (s + j);
		}
	}

	return (0);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: destination
 * @src: source
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	j = 0;
	for (j = 0; src[j]; j++)
	{
		dest[i] =  src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
