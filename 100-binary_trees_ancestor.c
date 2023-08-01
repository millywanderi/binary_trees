#include"binary_trees.h"

/**
 * recurse_ancestor - a function that recursively finds
 * the lower common ancestor
 * @root: pointer to the root node of the tree
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer of the lower common ancestor
 */
binary_tree_t *recurse_ancestor(binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *leftLCA = NULL, *rightLCA = NULL;

	/* base the case */
	if (!root || !first || !second)
		return (NULL);

	if (root == first || root == second)
		return (root);

	leftLCA = recurse_ancestor(root->left, first, second);
	rightLCA = recurse_ancestor(root->right, first, second);

	if (leftLCA && rightLCA)
		return (root);

	if (leftLCA)
		return (leftLCA);
	return (rightLCA);
}

/**
 * binary_trees_ancestor - a function that finds the lowest common
 * ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *root = NULL;

	/* base the case */
	if (first == NULL || second == NULL)
		return (NULL);

	/* find the root node of the tree */
	root = (binary_tree_t *)first;
	while (root->parent)
		root = root->parent;

	/* perform lowest common ancestor */
	return (recurse_ancestor(root, first, second));
}
