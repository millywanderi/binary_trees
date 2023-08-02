#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element to be converted
 * Return: pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t m = 0;

	/* check if array exists */
	if (!array)
		return (NULL);

	/* create the tree's root */
	tree = bst_insert(&tree, array[m++]);

	/* iterate through array */
	while (m < size)
	{
		bst_insert(&tree, array[m]);
		m++;
	}
	return (tree);
}
