#include "binary_trees.h"

/**
 * bst_search - this searches for a value
 * in a Binary Search Tree
 * @tree: this is the tree root
 * @value: the node value
 * Return: the pointer to the found node
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree && value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
