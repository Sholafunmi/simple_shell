#include "shell.h" 

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: array length
 * @old_size: The size in bytes of the old memory
 * @new_size: The size in bytes for the new memory
 * Return: returns a pointer to memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;
	char *new_result, *new_ptr;
	unsigned int t;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		result = malloc(new_size);
		if (result == NULL)
		{
			return (NULL);
		}
		return (result);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	new_result = ptr;
	result = (char *)malloc(sizeof(*new_result) * new_size);
	if (result == NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = result;
	
	for (t = 0; t < old_size && t < new_size; t++)
	{
		new_ptr[t] = *new_result++;
	}


	free(ptr);
	return (result);
}
