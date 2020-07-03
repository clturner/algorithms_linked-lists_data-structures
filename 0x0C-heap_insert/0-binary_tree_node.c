#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Entry point
 * @parent: pointer to parent
 * @value: value
 * Return: binary_tree_node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
        binary_tree_t *temp;

	temp = (binary_tree_t *)malloc(sizeof(heap_t));

	if (temp == NULL)
	  return (NULL);
	temp->n = value;
	temp->parent = parent;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}
