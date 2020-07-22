#include "binary_trees.h"

/**
 * binary_tree_is_full -  checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	/*If leaf node*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/*If both left and right are not NULL and left & right subtrees are full*/
	if (binary_tree_is_full(tree->left) == 1 &&
	    binary_tree_is_full(tree->right) == 1)
		return (1);
	return (0);
}
