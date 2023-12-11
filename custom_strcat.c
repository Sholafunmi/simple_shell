#include "simple_shell.h"


char* custom_strcat(char* destination, const char* source) 
{
    char* result = destination;

    // Move to the end of the destination string
    while (*destination) {
        destination++;
    }

    // Copy characters from source to destination
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }

    // Null-terminate the result
    *destination = '\0';

    return result;




	/*** char* ptr = destination;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*source != '\0') 
	{
		*ptr = *source;
		ptr++;
		source++;
	}

	*ptr = '\0';

	return destination; */
}
