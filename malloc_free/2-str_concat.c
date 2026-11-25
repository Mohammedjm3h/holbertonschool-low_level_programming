#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated space
 * @s1: the first string (NULL is treated as an empty string)
 * @s2: the second string (NULL is treated as an empty string)
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *new;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new[i] = s1[i];
	for (j = 0; j < len2; j++)
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}
