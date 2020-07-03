#include <stddef.h>
#include "sort.h"

/**
 * build_heap - build a heap of unsorted array values
 * @array: array to sort in heap
 * @size: size of array
 * @i: largest unsorted number in array
 * @total_size: total size of array
 * Return: void
 */

void build_heap(int *array, size_t size, int i, size_t total_size)
{
	int largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	size_t  store = 0;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		store = array[i];
		array[i] = array[largest];
		array[largest] = store;

		print_array(array, total_size);

		build_heap(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Entry point
 * @array: size of array
 * @size: size of array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;
	int store;

	for (i = size / 2 - 1; i >= 0; i--)
		build_heap(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		store = array[0];
		array[0] = array[i];
		array[i] = store;

		if (i == 0)
			break;

		print_array(array, size);

		build_heap(array, i, 0, size);
	}
}
