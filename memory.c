#include "shell.h"

/**
 * bfree - A function to free pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Return: 1 for Success, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
