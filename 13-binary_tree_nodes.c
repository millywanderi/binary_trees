#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes with atleast
 * 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count no of nodes
 * Return: 0 if the tree is NULL or Null pointer if not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
	{
		return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
	}
	return (0);
}
