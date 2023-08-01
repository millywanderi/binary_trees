#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds a sibling for the node
 * @node: pointer to the node to find the sibling
 * Return: 0 if the node/parent is NULL
 * or if the node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* base the case */
	if (!node || !node->parent)
		return (NULL);

	/* check for left or right child */
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
