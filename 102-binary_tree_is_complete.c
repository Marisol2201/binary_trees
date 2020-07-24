#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int cn;

	if (tree == NULL)
		return (0);

	cn = countNodes(tree);

	return (checkComplete(tree, 0, cn));
}

/**
 * countNodes - Count the total number of nodes in a Binary tree
 * @tree: pointer to the root node of the tree to count
 * Return: the number of nodes
 */
int countNodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + countNodes(tree->right) + countNodes(tree->left));
}

/**
 * checkComplete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to count
 * @index: position of the nodes
 * @numberNodes: total number of nodes in a Binary tree
 * Return: the number of nodes
 */
int checkComplete(const binary_tree_t *tree, int index, int numberNodes)
{
	/*Check if the tree is complete*/
	if (tree == NULL)
		return (1);

	if (index >= numberNodes)
		return (0);

	return (checkComplete(tree->left, 2 * index + 1, numberNodes) &&
			checkComplete(tree->right, 2 * index + 2, numberNodes));
}
