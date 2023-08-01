#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures
 * the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: 0 if the tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* declaration and initialization of depth */
	size_t dep = 0;

	/* base the case */
	if (!tree)
		return (0);

	/* iterate through the nodes path */
	while (tree)
	{
		tree = tree->parent;
		dep++;
	}

	/* if successful */
	return (dep - 1);
}
