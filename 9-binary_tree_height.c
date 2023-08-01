#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recurse_height(tree) - 1);
}

/**
 * recurse_height - measure the height
 * @tree: tree to be measured height
 * Return: height
 */
size_t recurse_height(const binary_tree_t *tree)
{
	size_t heightRight, heightLeft;

	if (tree == NULL)
		return (0);

	heightLeft = recurse_height(tree->left);
	heightRight = recurse_height(tree->right);

	if (heightLeft > heightRight)
		return (heightLeft + 1);
	else
		return (heightRight + 1);
}
