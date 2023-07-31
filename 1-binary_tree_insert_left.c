#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts left child
 * @parent: parent node pointer
 * @value: left child value
 * Return: pointer to the created node, otherwise NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (parent == NULL)
		return (NULL);

	/* allocate memory */
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	/* Initialize new node */
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* If left node already exists in a parent node*/
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
