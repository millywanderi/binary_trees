#include "binary_trees.h"

/**
 * loop_helper - a function that searches for in-order successor
 * @root: pointer to the root node
 * Return: pointer to in-order successor
 */
bst_t *loop_helper(bst_t *root)
{
	bst_t *curr = root;

	while ((curr != NULL) && (curr->left != NULL))
		curr = curr->left;
	return (curr);
}

/**
 * bst_remove - afunction that removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree to remove the node
 * @value: value to remove from the node
 * Return: pointer to new root node, otherwise NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_node = NULL;

	if (!root)
		return (root);

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else if (root->n == value)
	{
		if ((!root->left) && (!root->right))
		{
			free(root);
			return (NULL);
		}
		if (!root->left)
		{
			new_node = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new_node;
				root->parent->right = new_node;
			}
			new_node->parent = root->parent;
			free(root);
			return (new_node);
		}
		else if (!root->right)
		{
			new_node = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new_node;
				root->parent->right = new_node;
			}
			new_node->parent = root->parent;
			free(root);
			return (new_node);
		}
		else
		{
			new_node = loop_helper(root->right);
			root->n = new_node->n;
			root->right = bst_remove(root->right, new_node->n);
		}
	}
	return (root);
}
