# Heap Insert
## 1) function that creates a binary tree node:
## 2) function that inserts a value into a Max Binary Heap
### /**
### * struct binary_tree_s - Binary tree node
### *
### * @n: Integer stored in the node
### * @parent: Pointer to the parent node
### * @left: Pointer to the left child node
### * @right: Pointer to the right child node
### */
### struct binary_tree_s
### {
###    int n;
###    struct binary_tree_s *parent;
###    struct binary_tree_s *left;
###    struct binary_tree_s *right;
### };