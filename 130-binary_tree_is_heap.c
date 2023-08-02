#include "binary_trees.h"

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
	}
	return (0);
}

/**
 * recurse_complete -a function that tracks node posistion
 * @tree: pointer of the root node to the tree to track
 * @idx: index of the node
 * @size: size of tree
 * Return: 1 if complete, otherwise 0
 */
int recurse_complete(const binary_tree_t *tree, size_t idx, size_t size)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (idx >= size)
		return (0);

	left = recurse_complete(tree->left, (2 * idx) + 1, size);
	right = recurse_complete(tree->left, (2 * idx) + 1, size);

	if (left == 1 && right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_complete - afunction that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if the tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* base the case */
	if (tree == NULL)
		return (0);

	return (recurse_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * heap_helper - a function that checks binary heap property
 * @tree: pointer to the root node of the tree to be checked
 * Return: 1 if successful, otherwise 0
 */
int heap_helper(const binary_tree_t *tree)
{
	/* base the case */
	if (!tree)
		return (0);

	/* check for the root node */
	if ((!tree->left) && (!tree->right))
		return (1);

	/* determine the second last level */
	if (!tree->right)
		return (tree->n >= tree->left->n);

	/* check for left and right subtrees recursively */
	if ((tree->n >= tree->left->n) && (tree->n >= tree->right->n))
		return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
	return (0);
}

/**
 * binary_tree_is_heap - a function that checks if a binary tree is a valid
 * Max Binary Heap
 * @tree: pointer to the root node of the tree to be checked
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (binary_tree_is_complete(tree) && heap_helper(tree))
		return (1);
	return (0);
}
