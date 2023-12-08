#include "simple_shell.h"

char *custom_strcpy(char *dest, const char *src)
{
	char *destination = dest;

	while((*destination++ = *src++) != '\0');

	return dest;
}
