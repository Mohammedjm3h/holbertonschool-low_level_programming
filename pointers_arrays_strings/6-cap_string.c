#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	char *sep = " \t\n,;.!?\"(){}";
	int j = 0;

	while (sep[j] != '\0')
	{
		if (c == sep[j])
			return (1);
		j++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string to change
 *
 * Return: pointer to the changed string str
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122 &&
		    (i == 0 || is_separator(str[i - 1])))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
