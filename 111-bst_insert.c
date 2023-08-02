#include "binary_trees.h"

/**
 * recurse_bst_insert - a function that recursively insert search tree
 * @tree: pointer to the root node of the tree to be inserted
 * @value: value to be inserted
 * Return: pointer to the parent of the new node, otherwise NULL
 */
bst_t *recurse_bst_insert(bst_t *tree, int value)
{
	/* base the case */
	if (tree == NULL)
		return (NULL);

	/* check if the value is less than that in the node */
	if (value < tree->n)
	{
		if (tree->left)
			return (recurse_bst_insert(tree->left, value));
		return (tree);

	/* check if the value is greater that that in the node */
	else if (value > tree->n)
	{
		if (tree->right)
			return (recurse_bst_insert(tree->right, value));
		return (tree);
	}
	return (NULL);
}

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the tree the value to be inserted
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, otherwise NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newNode = NULL, *parent = NULL;

	if (!tree)
		return (NULL);
	/* create tree if it does not exists */
	if (!*tree)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	parent = recurse_bst_insert(*tree, value);
	/* create new node if the parent does not exist */
	if (parent != NULL)
		newNode = binary_tree_node(parent, value);
	return (NULL);
	/* point parent to the new node */
	if (value < parent->n)
		parent->left = newNode;
	parent->right = newNode;
	return (newNode);
}
