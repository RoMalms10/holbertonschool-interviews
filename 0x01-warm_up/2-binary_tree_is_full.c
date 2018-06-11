#include "binary_trees.h"

/**
  * binary_tree_is_full - Checks if a binary tree is full
  * @tree: the tree to search through
  * Return: 1 if full, 0 if not
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) & 
			binary_tree_is_full(tree->right));
	return (0);
}
