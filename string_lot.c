#include "shell.h"

/**
 * _strncat - Concantenates two strings
 * @dest: destination.
 * @src: source
 * @n: number
 * Return: Pointer to destination
 */

char *_strncat(char *dest, char *src, size_t n)
{
        size_t dest_length, dest_tl, t;

        dest_length = _strlen(dest);

        for (t = 0; t < n && src[t] != '\0'; t++)
        {
                dest_tl = dest_length + t;
                dest[dest_tl] = src[t];
        }

        dest[dest_tl] = '\0';

        return (dest);
}

/**
 * _strspn - calculate the length of the initial segment of a string.
 * @s: string.
 * @accept: big string
 * Return: returns integer
 */

int _strspn(char *s, char *input)
{
	int lot = 0;
	int t, r;

	r = 0;
	while (s[r])
	{
		for (t = 0; input[t]; t++)
		{
			if (*s == input[t])
		 	{
				lot++;
				break;
			}
		}
		r++;
	}
	return (lot);
}

/**
 * _strcmp - Compares two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: interger
 * */

int _strcmp(char *s1, char *s2)
{
	int v;
	int p;

	v = 0;
	while (s1[v] && s2[v])
	{

		if (s1[v] != s2[v])
		{
			p = s1[v] - s2[v];

			return (p);
		}
		v++;
	}

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @str2: string1.
 * @str2: string2.
 * @n: n number of the strings to compare.
 * Return: integer
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t p;

	if (s1 == NULL)
	{
		return (-1);
	}
		for (p = 0; p < n && s2[p]; p++)
		{
			if (s1[p] != s2[p])
			{
				return (1);
			}
		}
		return (0);
}
