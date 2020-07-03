#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to a pointer of the start of the list
 * @n: integer to be included in node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * insert_node - adds a new node at the proper index of a sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @new: new node to add to sorted list
 * @number: integer to be included in new node
 * @save: temporary node to hold pointer value while adding a new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *save;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		add_nodeint(&*head, number);
	}
	else
	{
		current = *head;
		save = current->next;
		while (current)
		{
			if (number < current->n)
			{
				add_nodeint(&*head, number);
				return (new);
			}
			if (number > current->n && number <= current->next->n)
                        {
                                save = current->next;
                                current->next = new;
                                new->next = save;
                                return (new);
                        }
			if (number > current->n && current->next->next == NULL)
			{
				add_nodeint_end(&*head, number);
				return (new);
			}
			current = current->next;
		}
	}
	return (new);
}
