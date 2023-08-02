#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs right rotation on a tree
 * @tree: pointer to the root node of the tree to be rotated
 * Return: pointer to the new roteted root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_node = NULL, *root = NULL;

	/* check if the root node is NULL */
	if (!tree)
		return (tree);

	/* if root does not have children */
	if ((!tree->left) && (!tree->right))
		return (tree);

	/* set new root pointer */
	new_node = tree->left;
	tree->left = new_node->right;
	if (new_node->right != NULL)
		new_node->right->parent = tree;
	/* swap parents */
	new_node->parent = tree->parent;
	if (!tree->parent)
		root = new_node;
	else if (tree == tree->parent->right)
		tree->parent->right = new_node;
	else
		tree->parent->left = new_node;
	/* move tree to the right of the new node */
	new_node->right = tree;
	tree->parent = new_node;
	/* check if the current root is NULL */
	if (root != NULL)
		return (root);
	return (new_node);
}
