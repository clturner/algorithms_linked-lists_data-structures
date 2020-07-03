#include <stdio.h>
#include <math.h>

#include "menger.h"

/**
 * is_it_filled - Entry point
 *
 * @i: index of row of sponge
 * @j: index of column of sponge
 *
 * Return: 0 if position is non filled, 1 if position is X
 */


int is_it_filled(int i, int j)
{
	while (i && j)
	{
/* Every non filled space in the carpet has the indexes i && j % 3 == 1 */
		if (i % 3 == 1 && j % 3 == 1)
		{
			return (0);
		}
      /* Deviding indexs by 3 changes carpet size to next smallest level */
      /* Continue while loop to check succesivle smaller level carpets */
      /* If i or j reaches 0 than the current index position must be an X */
		i = i / 3;
		j = j / 3;
	}
	return (1);
}

/**
 * menger - Entry point
 *
 * @level: level of menger sponge to draw
 * Return: Void function
 */

void menger(int level)
{
	int i, j;
	int size;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_it_filled(i, j) == 1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
