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
	const binary_tree_t *aux1 = NULL, *aux2 = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)second);

	aux1 = first;

	while (aux1)
	{
		aux2 = second;
		while (aux2)
		{
			if (aux1 == aux2)
				return ((binary_tree_t *)aux1);
			aux2 = aux2->parent;
		}
		aux1 = aux1->parent;
	}
	return (NULL);
}
