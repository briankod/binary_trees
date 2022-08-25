#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value > tree->n)
		return (bst_search(tree->right, value));
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return ((bst_t *)tree);
}
