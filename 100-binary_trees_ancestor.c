#include "binary_trees.h"
/**
 * *binary_trees_ancestor -   finds the lowest common ancestor of two nodes
 * @first:  is a pointer to the first node
 * @second:  is a pointer to the second node
 * Return: If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	while (binary_tree_height(second) != binary_tree_height(first))
	{
		if (binary_tree_height(first) == binary_tree_height(second))
			return (second->parent);
		while (binary_tree_height(first) > binary_tree_height(second))
		{
			second = first;
			return (second->parent);
		}
		return (second->parent);
	}
	return (second->parent);
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