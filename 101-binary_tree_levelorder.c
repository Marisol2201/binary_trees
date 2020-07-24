#include "binary_trees.h"

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
 * print_level - change the root node to it’s left and right children and
 * ...print both sub-trees
 * @tree: is a pointer to the root node of the three to traverse
 * @level_no: level to print
 * @func: pointer to a function to call for each node
 * Return: void
 */

void print_level(const binary_tree_t *tree, void (*func)(int), int level_no)
{
	/*Prints the nodes in the tree having a level = level_no*/
	/*We have a auxiliary tree node for printing the root of every sub-tree*/
	if (!tree)
		return;
	if (level_no == 0)
	{
		/*We are at the top of a sub-tree, so print the auxiliary tree node*/
		(*func)(tree->n);
	}
	else
	{
		/*Make the auxiliary root node to be the left and right nodes for*/
		/*...the sub-trees and decrease level by 1, since*/
		/*...you are moving from top to bottom*/
		print_level(tree->left, &(*func), level_no - 1);
		print_level(tree->right, &(*func), level_no - 1);
	}
}

/**
 * print_tree_level_order - print nodes for every level
 * @tree: is a pointer to the root
 * @func: pointer to a function to call for each node
 * Return: void
 */

void print_tree_level_order(const binary_tree_t *tree, void (*func)(int))
{
	/*i is the level*/
	int i = 0;
	int height = binary_tree_height(tree);

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
	{
		/*Print the ith level*/
		print_level(tree, &(*func), i);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * ...traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * ...The value in the node must be passed as a parameter to this function
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	print_tree_level_order(tree, &(*func));
}
