#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: pointer to the string
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len = 0;
	int n;
	int i;

	while (str[len] != '\0')
		len++;
	n = (len + 1) / 2;
	i = len - n;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
