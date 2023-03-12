#include "menger.h"
#include <math.h>

/**
 * draw_square - function recursively draws a square at a given level
 *
 * @level: the level of the Menger Sponge to draw
 * @row: line number variable
 * @col: collone number variable
 * @size: larger square of a given size
 */


void draw_square(int level, int row, int col, int size)
{
	if (level == 0)
	{
		printf("#");
	}
	else
	{
		int new_size = size / 3;
		int r = row / size;
		int c = col / size;

		if (r == 1 && c == 1)
		{
			printf(" ");
		}
		else
		{
			draw_square(level - 1, row % size, col % size, new_size);
		}
	}
}

/**
 * menger - a function that draws a 2D Menger Sponge
 *
 * @level: the level of the Menger Sponge to draw
 */


void menger(int level)
{
	if (level < 0)
	{
		return;
	}
	int size = (int) pow(3, level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			draw_square(level, row, col, size);
		}
		printf("\n");
	}
}
