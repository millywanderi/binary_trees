#include "binary_trees.h"

/**
 * binary_tree_inorder - a function that goes through a
 * binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if either the pointer is NULL*/
	if (!tree || !func)
		return;

	/* recurse left side */
	binary_tree_inorder(tree->left, func);
	func(tree->n);

	/* recurse right side */
	binary_tree_inorder(tree->right, func);
}
