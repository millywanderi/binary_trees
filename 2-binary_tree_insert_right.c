#include "binary_trees.h"

/**
 * binary_tree_insert_right- a function that inserts right child
 * @parent: parent node pointer
 * @value: value to be inserted on the created node
 * Return: pointer to the created node, otherwise NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child = NULL;

	/* if parent doesn't exist */
	if (parent == NULL)
		return (NULL);

	/* Allocate memory to the right child */
	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	/* Assign values to the right child */
	right_child->n = value;
	right_child->left = NULL;
	right_child->right = NULL;
	right_child->parent = parent;

	/* If right child already exists */
	if (parent->right != NULL)
	{
		right_child->right = parent->right;
		(parent->right)->parent = right_child;
	}
	parent->right = right_child;
	return (right_child);
}
