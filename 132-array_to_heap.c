#include "binary_trees.h"

/**
 * array_to_heap - this builds a Max Binary Heap tree
 * @array: the pointer to the first element of the array
 * @size: the number of elements in the array
 * Return: the pointer to the root node of the AVL tree
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
}
