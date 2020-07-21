#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: If tree is NULL, the function must return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int count = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		count += binary_tree_size(tree->left);
	if (tree->right != NULL)
		count += binary_tree_size(tree->right);

	return (count);
}
