#include "binary_trees.h"

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
	childL = recurse_height(tree->left) - 1;
	childR = recurse_height(tree->right) - 1;

	/* calculate the balance factor */
	return (childL - childR);
}

/**
 * recurse_balance - a function that checks for tree and subtrees
 * @tree: pointer to the root node of the tree to check
 * Return: balance factor
 */
int recurse_balance(const binary_tree_t *tree)
{
	int factorBal;

	/* base the case */
	if (tree == NULL)
		return (0);

	/* check the balance factor */
	factorBal = binary_tree_balance(tree);

	if (factorBal != 0)
		return (factorBal);

	return (recurse_balance(tree->left) || recurse_balance(tree->right));
}
/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to be checked
 * Return: 0 if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* base the case */
	if (!tree)
		return (0);

	/* check for balance factor */
	if (recurse_balance(tree) == 0)
	{
		return (1);
	}
	return (0);
}
