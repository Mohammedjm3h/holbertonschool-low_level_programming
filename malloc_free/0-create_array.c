#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and fills it with a char
 * @size: number of chars in the array
 * @c: the char to fill the array with
 *
 * Return: pointer to the array, or NULL if size is 0 or malloc fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (0);
	arr = malloc(sizeof(char) * size);
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = c;
		i++;
	}
	return (arr);
}
