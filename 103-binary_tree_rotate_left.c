#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs left rotation on a tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_node = NULL, *root = NULL;

	/* check if the root node is NULL */
	if (!tree)
		return (tree);

	/* if root does not have children */
	if ((!tree->left) && (!tree->right))
		return (tree);

	/* set new root pointer */
	new_node = tree->right;
	tree->right = new_node->left;
	if (new_node->left != NULL)
		new_node->left->parent = tree;
	/* swap parents */
	new_node->parent = tree->parent;
	if (!tree->parent)
		root = new_node;
	else if (tree == tree->parent->left)
		tree->parent->left = new_node;
	else
		tree->parent->right = new_node;
	/* move tree to the left of the new node */
	new_node->left = tree;
	tree->parent = new_node;
	/* check if the current root is NULL */
	if (root != NULL)
		return (root);
	return (new_node);
}
