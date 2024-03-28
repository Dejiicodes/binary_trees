#include "binary_trees.h"

/**
 * recursive_depth - this measures the depth of
 * a node in a binary tree
 * @tree: this is the tree root
 * Return: the depth of a node in a binary tree
 */

size_t recursive_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (recursive_depth(tree->parent) + 1);
}

/**
 * binary_tree_depth - this calls recursive_depth to
 * return the depth of a node in a binary tree
 * @tree: this is the tree root
 * Return: the depth of the tree or 0 if tree is NULL;
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recursive_depth(tree));
}

/**
 * binary_tree_uncle - this finds the lowest common
 * ancestor of two nodes
 * @first: the pointer to the first node
 * @second: the pointer to the second node
 * Return: the pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));

	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}
