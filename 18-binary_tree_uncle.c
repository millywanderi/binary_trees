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

/**
 * binary_tree_uncle - a function that finds for an uncle of a node
 * @node: pointer to the node to find uncle
 * Return: pointer to the uncle node, otherwise
 * NULL if the node is NULL or does not have an uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* base the case */
	if (!node)
		return (NULL);

	/* check for uncle in a node */
	if (!node->parent)
		return (NULL);

	/* checks for same level node with parent */
	return (binary_tree_sibling(node->parent));
}
