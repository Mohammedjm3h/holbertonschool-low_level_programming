#include "main.h"

/**
 * _strcpy - copies a string, including the null byte, to a buffer
 * @dest: pointer to the buffer to copy into
 * @src: pointer to the string to copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
