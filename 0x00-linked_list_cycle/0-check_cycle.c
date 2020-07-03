#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - prints all elements of a listint_t list
 * @list: pointer to a linked list
 * @head: pointer to head of linked list
 * @current: pointer to current node for cycle check
 * @temp1: pointer to first temp node for cycle check
 * @temp2: pointer to second node for cycle check
 * Return: 0 if no cycle in list: 1 if there is a cycle in list
 */

int check_cycle(listint_t *list)
{
	listint_t *head;
	listint_t *current;
	listint_t *temp1;
	listint_t *temp2;
	int count;

	count = 2;
	head = list;
	current = head;
	while (current->next != NULL)
	{
		temp1 = current;
		temp2 = current->next;
		while (temp2)
		{
			if (temp2->next == NULL)
			{
				return(0);
			}
			if (temp2 == temp1)
			{
				return(1);
			}
			temp2 = temp2->next;
			if (count % 2 != 0)
			{
				temp1 = temp1->next;
			}
			count = count + 1;
		}
		current = current->next;

	}
	return(23);
}
