#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

typedef struct binary_tree_s avl_t;

typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

avl_t *sorted_array_to_avl(int *array, size_t size);

void binary_tree_print(const binary_tree_t *tree);


#endif
