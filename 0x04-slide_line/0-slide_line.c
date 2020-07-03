#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

int *move_nums_together(int *line, int size)
{
	int count = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[count++] = line[i];
		}
	}
	while (count < size)
	{
		line[count++] = 0;
	}
	return(line);

}

int *add_equal_nums(int *line, size_t size)
{
	size_t i = 0;
	int j = 1;

	while (i < size)
	{
		j = i + 1;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			move_nums_together(line, size);
			i++;
		}
		else
		{
			i++;
		}
	}
	return(line);
}

int *reverse_the_array(int *line, size_t size)
{
	size_t i;
	int temp;

	for (i = 0; i < size/2; ++i)
	{
		temp = line[i];
		line[i] = line[size - 1 - i];
		line[size - 1 - i] = temp;
	}
	return(line);
}


int slide_line(int *line, size_t size, int direction)
{
	if (direction == 23)
	{
		move_nums_together(line, size);
		add_equal_nums(line, size);
	}
	else
	{
		reverse_the_array(line, size);
		move_nums_together(line, size);
		add_equal_nums(line, size);
		reverse_the_array(line, size);
	}
	return(1);
}
