#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * pprint_grid - prints a sand pile
 * @grid: grid[N][N] sandpile
 * Return: void
 */
static void pprint_grid(int grid[N][N])
{
	int i, j;

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
 * grid_checker - checks a sandpile for stability
 * @grid1: grid1[N][N] sandpile
 * Return: void
 */
int grid_checker(int grid1[N][N])
{
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (grid1[y][x] >= 4)
			{
				return (1);
			}
		}
	}
	return (0);
}
/**
 * topple - checks a sandpile for stability
 * @grid1: grid1[N][N] sandpile
 * Return: void
 */
void topple(int grid1[N][N])
{
	int y, x;
	int check_grid[N][N] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (grid1[y][x] >= 4)
				check_grid[y][x] = 1;
		}
	}
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (check_grid[y][x] == 1)
			{
				grid1[y][x] -= 4;
				if (y + 1 < 3)
					grid1[y + 1][x] += 1;
				if (y - 1 > -1)
					grid1[y - 1][x] += 1;
				if (x + 1 < 3)
					grid1[y][x + 1] += 1;
				if (x - 1 > -1)
					grid1[y][x - 1] += 1;
			}
		}
	}
}


/**
 * add - adds two sand piles and topples until stability
 * @grid1: 1st grid to add
 * @grid2: 2nd grid to add
 * Return: added sandpile
 */

void add(int grid1[N][N], int grid2[N][N])
{
	int y, x = 0;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			grid1[y][x] = grid1[y][x] + grid2[y][x];
		}
	}
}

/**
 * sandpiles_sum - adds two sand piles and topples until stability
 * @grid1: grid1[N][N] sandpile
 * @grid2: grid2[N][N] sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[N][N], int grid2[N][N])
{
	add(grid1, grid2);

	if (grid_checker(grid1) == 1)
	{
		printf("=\n");
		pprint_grid(grid1);
	}
	while (grid_checker(grid1) == 1)
	{
		topple(grid1);
		if (grid_checker(grid1) == 1)
		{
			printf("=\n");
			pprint_grid(grid1);
		}
	}
}
