#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to reverse
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char tmp;

	while (s[end] != '\0')
		end++;
	end--;
	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}
