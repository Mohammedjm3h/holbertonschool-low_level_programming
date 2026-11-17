#include "main.h"

/**
 * _strncpy - copies at most n bytes of src into dest
 * @dest: pointer to the buffer to copy into
 * @src: pointer to the string to copy
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
