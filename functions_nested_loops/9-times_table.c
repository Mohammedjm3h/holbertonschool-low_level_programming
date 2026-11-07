#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row = 0;
	int col;
	int product;

	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			product = row * col;
			if (col != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
				{
					_putchar(' ');
				}
			}
			if (product >= 10)
			{
				_putchar('0' + product / 10);
			}
			_putchar('0' + product % 10);
			col++;
		}
		_putchar('\n');
		row++;
	}
}
