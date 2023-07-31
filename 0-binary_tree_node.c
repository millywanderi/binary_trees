#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: parent node pointer
 * @value: new node value
 * Return: pointer to the new node if successful, otherwise NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/*Allocate memory to the new node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	/*Assign new values to the new node*/
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
