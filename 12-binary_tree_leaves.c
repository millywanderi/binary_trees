#include "binary_trees.h"

/**
 * binary_tree_leaves - a function the counts the leaves in a binary treee
 * @tree: pointer to the root node of the tree to count leaves
 * Return: 0 if the tree is NULL or NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* declaration and initialization of leaf */
	size_t leaf = 0;

	/* base the case */
	if (!tree)
		return (0);

	/* check if the node is a leaf */
	if (!tree->left && !tree->right)
		return (1);

	/* count left and right nodes recursively */
	leaf = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (leaf);
}
