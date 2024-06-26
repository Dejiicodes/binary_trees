#include "binary_trees.h"

/**
 * bst_in - this checks if node is inserted
 * @tree: this is the tree root
 * @value: the node value
 * Return: the pointer to the new node
 */

bst_t *bst_in(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (bst_in(&((*tree)->left), value));
		}
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			return (bst_in(&((*tree)->right), value));
		}
	}

	return (NULL);
}

/**
 * bst_insert - this inserts a value in a Binary Search Tree
 * @tree: this is the tree root
 * @value: the node value
 * Return: the pointer to the new node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_in(tree, value));
§}
