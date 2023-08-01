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

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * the balance factor
 * Return: 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int childL = 0, childR = 0;

	/* base the case */
	if (!tree)
		return (0);

	/* checks for balance factor in a node */
	if (!tree->left && !tree->right)
		return (0);

	/* calculate the left and right trees heights */
	childL = binary_tree_height(tree->left);
	childR = binary_tree_height(tree->right);

	/* calculate the balance factor */
	return (childL - childR);
}
