#include "main.h"
/**
 * _isupper - check for uppercase character
 * @c: the character to check
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 56 && c <= 90)
	{
		return (1);
	}
	return (0);
}
