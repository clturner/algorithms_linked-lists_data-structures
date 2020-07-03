#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * @head: head of linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * Return: Always 0.
 */

int is_palindrome(listint_t **head)
{
	listint_t *current;
	int count;
	int count1;
	int *array = NULL;
	int length = 0;

	head = head;
	current = *head;
	count = 1;
	count1 = 0;

	if (*head == NULL)
	{
		return(1);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count += 1;
	}

	array = malloc(sizeof(int)*count);
	current = *head;
	for (count1 = 0; current->next != NULL; count1++)
	{
		array[count1] = current->n;
		current = current->next;
	}
	array[count1] = current->n;

	length = (count / 2);
	count1 = 0;
	count = count - 1;
	for (count1 = 0; count1 <= length; count1++)
	{
		if (array[count1] == array[count])
		{
			count -= 1;
			if (count1 == length)
			{
				return(1);
			}
		}
		else
			return(0);
	}
	return(23);
}
