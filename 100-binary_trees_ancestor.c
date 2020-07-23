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
	const binary_tree_t *curr1 = NULL, *curr2 = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)second);

	curr1 = first;

	while (curr1)
	{
		curr2 = second;
		while (curr2)
		{
			if (curr1 == curr2)
				return ((binary_tree_t *)curr1);
			curr2 = curr2->parent;
		}
		curr1 = curr1->parent;
	}
	return (NULL);
}
