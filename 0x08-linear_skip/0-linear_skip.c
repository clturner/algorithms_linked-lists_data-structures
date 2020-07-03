#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * print_value - prints index and value
 * @index: index of node to print
 * @n: value of node to print
 * Return: void
 */
void print_value(size_t index, int n)
{
	printf("Value checked at index [%lu] = [%i]\n", index, n);
}

/**
 * print_found - prints index and express->index
 * @index1: index
 * @index2: express->index
 * Return: void
 */
void print_found(size_t index1, size_t index2)
{
	printf("Value found between indexes [%lu] and [%lu]\n", index1, index2);
}

/**
 * size - counts mnodes in a linked list
 * @list: head to a linked list to search
 * Return: count of nodes
 */
size_t size(skiplist_t *list)
{
	skiplist_t *nxt;
	size_t count;

	count = 0;
	nxt = list;
	while (nxt->next != NULL)
	{
		nxt = nxt->next;
		count += 1;
	}
	return (count);
}

/**
 * linear_skip - searches a linear linked list for a value
 * @list: head to a linked list to search
 * @value: value to search for
 * Return: node of linked list or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ex, *nxt, *last;
	size_t count;

	ex = list;
	nxt = list;
	count = size(list);
	if (ex == NULL)
		return (NULL);
	for (ex = list; ex->index != 15; ex = ex->express)
	{
		print_value(ex->express->index, ex->express->n);
		if (value <= ex->express->n)
		{
			print_found(ex->index, ex->express->index);
			for (nxt = ex; nxt->index <= ex->express->index; nxt = nxt->next)
			{
				print_value(nxt->index, nxt->n);
				if (value == nxt->n)
					return (nxt);
				if (nxt->index == ex->express->index)
					return (NULL);
			}
		}
		if (count - ex->express->index <= 3)
			break;
	}
	nxt = ex->express; last = ex->express;
	while (nxt->next != NULL)
		nxt = nxt->next;
	print_found(ex->express->index, nxt->index);
	for (; last->index <= nxt->index; last = last->next)
	{
		print_value(last->index, last->n);
		if (count == last->index && value > last->n)
			return (NULL);
		if (value == last->n)
			return (nxt);
	}
	return (NULL);
}
