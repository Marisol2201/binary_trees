#include "binary_trees.h"

/**
 * *binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (!tree || !tree->left)
		return (NULL);

	new_tree = tree->left;
	tree->left = new_tree->right;
	new_tree->right = tree;
	tree->parent = new_tree;

	return (new_tree);
}
