#include "binary_trees.h"

/**
 * binary_tree_size - this measures the size of a binary tree
 * @tree: this is the tree root
 * Return: the size of the tree or 0 if tree is NULL;
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - this checks to see if tree is complete
 * @tree: the pointer to the tree root
 * @i: the node index
 * @cnodes: the number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - this calls to tree_is_complete function
 * @tree: this is the tree root
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}
