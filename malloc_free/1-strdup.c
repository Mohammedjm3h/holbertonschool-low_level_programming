#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to copy
 *
 * Return: pointer to the copy, or NULL if str is NULL or malloc fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int len = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
