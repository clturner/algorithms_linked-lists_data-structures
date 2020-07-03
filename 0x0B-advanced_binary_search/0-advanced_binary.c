#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * pa - prints an array
 * @array: array
 * @start: index to start printing
 * @finish: index to stop printing
 * Return: Always EXIT_SUCCESS
 */

void pa(int *array, int start, int finish)
{
	int j;

	printf("Searching in array: ");
	for (j = start; j < finish; j++)
	{
		if (j != finish - 1)
		{
			printf("%i, ", array[j]);
		}
		else
		{
			printf("%i", array[j]);
		}
	}
	printf("\n");
}

/**
 * frmt - formats print arguments
 * @num: number
 * @array: array
 * @low: low index
 * @mid: mid index
 * @high: high index
 * Return: Always EXIT_SUCCESS
 */

void frmt(int num, int *array, int low, int mid, int high)
{
	if (num == 1)
	{
		if (mid % 2 == 0)
			pa(array, low - 1, mid + 1);
		else
			pa(array, low, mid);
	}
	if (num == 2)
	{
		if (mid % 2 == 0)
			pa(array, mid, high);
		else
		{
			if ((high - mid) % 2 == 0)
				pa(array, mid, high);
			else
				pa(array, mid, high - 1);
		}
	}
	if (num == 3)
	{
		if (mid % 2 == 0)
			pa(array, low, mid + 1);
		else
			pa(array, low, mid);
	}
	if (num == 4)
	{
		if (mid % 2 == 0)
		{
			if (high == mid + 1)
				pa(array, mid, high);
			else
				pa(array, mid + 1, high);
		}
		else
			pa(array, mid, high);
	}
}

/**
 * checker - prints an array
 * @array: array
 * @start: index to start checkin
 * @value: value
 * Return: Always EXIT_SUCCESS
 */

int checker(int *array, int start, int value)
{
	int i;

	for (i = start; i >= 0; i--)
	{
		if (array[i] == value)
		{
			return (0);
		}
		if (array[i] < value)
		{
			return (1);
		}
	}
	return (1);
}


/**
 * bs - recusive binary search
 * @array: array
 * @low: index of lowest part of subarray
 * @high: index to highest part of sub array
 * @value: value to search for
 * @size: size of array
 * Return: Always EXIT_SUCCESS
 */

int bs(int *array, int low, int high, int value, size_t size)
{
	int mid;
	int check;
	int num = 0;

	if (high >= low)
	{
		mid = low + (high - low) / 2;
		if (mid == high)
			return (-1);
		if (array[mid] == value)
		{
			check = checker(array, mid - 1, value);
			if (check == 0)
			{
				num = 1;
				frmt(num, array, low, mid, high);
				return (bs(array, low, mid + 1, value, size));
			}
			else
			{
				num = 2;
				frmt(num, array, low, mid, high);
				return (mid);
			}
		}
		if (array[mid] > value)
		{
			num = 3;
			frmt(num, array, low, mid, high);
			return (bs(array, low + 1, mid, value, size));
		}
		if (array[mid] < value)
		{
			num = 4;
			frmt(num, array, low, mid, high);
			return (bs(array, mid + 1, high, value, size));
		}
	}
	return (-1);
}

/**
 * advanced_binary - advanced binary search
 * @array: array
 * @size: size of array
 * @value: value to search for
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	int idx;

	if (array == NULL || size < 1)
	{
		return (-1);
	}
	pa(array, 0, size);
	idx = bs(array, 0, size, value, size);
	return (idx);
}
