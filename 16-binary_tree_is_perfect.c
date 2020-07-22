#include "binary_trees.h"

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree:  is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree) == 0)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		if (binary_tree_is_perfect(tree->left) == 1 &&
		    binary_tree_is_perfect(tree->right) == 1)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
		return (0);

	height_left = 1 + binary_tree_height(tree->left);
	height_right = 1 + binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
		return (0);

	if (tree->left)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		height_right = binary_tree_height(tree->right) + 1;

	return (height_left - height_right);
}
