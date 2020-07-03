#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to root of a binary tree
 * @value: integer value for newNode
 * Return: newNode of binary tree
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
	avl_t *newNode;

	newNode = malloc(sizeof(avl_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;
	if (!newNode)
	{
		return (NULL);
	}
	return (newNode);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to a binary tree
 * Return: count of nodes as height
 */
size_t binary_tree_height(avl_t *tree)
{
	size_t count;
	size_t count1;

	count = 0;
	count1 = 0;
	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
	{
		return (0);
	}
	count = binary_tree_height(tree->left);
	count1 = binary_tree_height(tree->right);
	if (count1 > count)
	{
		return (count1 + 1);
	}
	return (count + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a tree
 * @tree: pointer to a tree
 * Return: balance factor
 */
int binary_tree_balance(avl_t *tree)
{
	int count;
	int count1;
	avl_t *temp;
	avl_t *temp1;

	temp1 = tree;
	temp = tree;
	count1 = 0;
	count = 0;
	if (tree == NULL)
	{
		return (0);
	}
	while (temp->left != NULL)
	{
		temp = temp->left;
		count += 1;
	}
	while (temp1->right != NULL)
	{
		temp1 = temp1->right;
		count1++;
	}
	return (count - count1);
}

/**
 * binary_tree_rotate_right - rotates a node of tree to right
 * @tree: pointer to a tree
 * Return: tree
 */
avl_t *binary_tree_rotate_right(avl_t *tree)
{
	avl_t *temp;
	avl_t *temp1;
	avl_t *temp2;

	temp = tree;
	temp1 = tree->left;
	temp2 = NULL;
	if (tree == NULL)
		return (tree);
	if (tree->right == NULL && tree->left == NULL)
	{
		return (tree);
	}
	if (tree->right != NULL && tree->left == NULL)
	{
		return (tree);
	}
	temp->parent = temp1;
	temp->left = NULL;
	if (temp1->right != NULL)
	{
		temp2 = temp1->right;
		temp2->parent = temp;
		temp->left = temp2;
	}
	temp1->right = temp;
	temp1->parent = NULL;
	return (temp1);
}

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to tree
 * Return: pointer to new tree
 */
avl_t *binary_tree_rotate_left(avl_t *tree)
{
	avl_t *temp;
	avl_t *temp1;
	avl_t *temp2;

	temp = tree;
	temp1 = tree->right;
	temp2 = NULL;
	if (tree == NULL)
		return (tree);
	if (tree->left == NULL && tree->right == NULL)
	{
		return (tree);
	}
	if (tree->left != NULL && tree->right == NULL)
	{
		return (tree);
	}
	temp->parent = temp1;
	temp->right = NULL;
	if (temp1->left != NULL)
	{
		temp2 = temp1->left;
		temp2->parent = temp;
		temp->right = temp2;
	}
	temp1->left = temp;
	temp1->parent = NULL;
	return (temp1);
}

/**
 * insert - inserts a new node into a binary tree
 * @tree: pointer to tree
 * @n: inger value of n for new node
 * Return: pointer to new tree
 */
avl_t *insert(avl_t *tree, int n)
{
	int tree_node_balace;

	if (tree == NULL)
		return(binary_tree_node(tree, n));
	if (n < tree->n)
	{
		tree->left = insert(tree->left, n);
	}
	else if (n > tree->n)
	{
		tree->right = insert(tree->right, n);
	}
	else
		return(tree);

	tree_node_balace = binary_tree_balance(tree);

	if (tree_node_balace > 1 && n < tree->left->n)
	{

		return(binary_tree_rotate_right(tree));
	}
	if (tree_node_balace < -1 && n > tree->right->n)
	{
		return(binary_tree_rotate_left(tree));
	}
	if (tree_node_balace > 1 && n > tree->right->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return(binary_tree_rotate_right(tree));
	}
	if (tree_node_balace < -1 && n < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return(tree);
}

/**
 * sorted_array_to_avl - inserts value from array into avl tree
 * @tree: pointer to tree
 * @tree: size of tree
 * Return: pointer to new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *btree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		btree = insert(btree, array[i]);
	}
	return(btree);
}
