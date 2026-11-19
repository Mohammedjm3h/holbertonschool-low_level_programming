#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: pointer to the rows of the board (each row has 8 squares)
 *
 * Return: nothing
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
			_putchar(a[row][col]);
		_putchar('\n');
	}
}
