#include "simple_shell.h"
/**
 * custom_strcmp - This compares two strings.
 * @str1: First string to compare.
 * @str2: Second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero
 * if str1 is found, respectively, to be less than, to match, or be greater
 * than str2.
 */

int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1) - (*(unsigned char *)str2);
}
