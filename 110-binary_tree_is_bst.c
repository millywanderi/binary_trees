#include "binary_trees.h"

/**
 * recurse_bst - a function that ecursively checks for BST
 * @tree: pointer to the root node of the tree to be checked
 * @mini: current minimum
 * @maxi: current maximum
 * Return:  if BST, otherwise 0
 */
int recurse_bst(const binary_tree_t *tree, int mini, int maxi)
{
	/* base the case */
	if (tree == NULL)
		return (1);

	/* check if the tree is min or maxi */
	if ((tree->n < mini) || (tree->n > maxi))
		return (0);
	return (recurse_bst(tree->left, mini, tree->n - 1)
		&& recurse_bst(tree->right, tree->n + 1, maxi));
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* base the case */
	if (tree == NULL)
		return (0);
	return (recurse_bst(tree, INT_MIN, INT_MAX));
}
