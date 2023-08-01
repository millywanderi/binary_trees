#include "binary_trees.h"

/**
 * full_recurse - recursive component of full check
 * @tree: root of the tree
 * Return: 1 if full, otherwise 0
 */
int full_recurse(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	else
		return (full_recurse(tree->left) * full_recurse(tree->right));

}
/**
 * binary_tree_is_full - a function that checks if the binary
 * tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if the tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* base the case */
	if (tree == NULL)
		return (0);

	return (full_recurse(tree));
}
