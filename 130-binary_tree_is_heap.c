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
 * tree_is_complete - this checks if tree is complete
 * @tree: the pointer to the tree root
 * @i: this is the node index
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

/**
 * check_parent - this checks if parent has a greater value than its childs
 * @tree: the pointer to the node
 * Return: 1 if parent has a greater value, 0 otherwise
 */

int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - this checks if an input tree is a Max Binary Heap
 * @tree: the pointer to the root of the tree
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
