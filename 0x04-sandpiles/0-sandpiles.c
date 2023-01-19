#include "sandpiles.h"

/**
 * print_sandpiles - function that print grids
 *
 * @grid: grid of sandpile
 * Return: None
 */


void print_sandpiles(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}

}


/**
 * is_stable - function booleen that return 1 if grid is stable
 * @grid1: grid of sandpile1
 * @grid2: grid of sandpile2
 * Return: 1 if is stable
 */

int is_stable(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;
	int stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
			if (grid1[i][j] > 3)
				stable = 0;
		}
	}
	return (stable);
}


/**
 * sum_grids - function that add two grids
 *
 * @grid1: grid of sandpile1
 * @grid2: grid of sandpile2
 * Return: None
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0;  j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * toppling - function that iterate sandpile
 *
 * @grid1: grid of sandpile1
 * @grid2: grid of sandpile2
 * Return: None
 */
void toppling(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				if (i > 0)
					grid1[i - 1][j] += 1;
				if (j < 2)
					grid1[i][j + 1] += 1;
				if (i < 2)
					grid1[i + 1][j] += 1;
				if (j > 0)
					grid1[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
}

/**
 * sandpiles_sum - function that sum sandpile
 *
 * @grid1: grid of sandpile1
 * @grid2: grid of sandpile2
 * Return: None
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!is_stable(grid1, grid2))
	{
		print_sandpiles(grid1);
		toppling(grid1, grid2);
	}
}
