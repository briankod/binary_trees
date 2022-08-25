#include "binary_trees.h"

/**
 * count_node - function that counts the number of nodes
 * @tree: a pointer to the root node of the tree
 * Return: number of nodes
 */
unsigned int count_node(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_node(tree->left) +
			count_node(tree->right));
}


/**
 * is_complete - Helper function to check completeness
 * @tree: a pointer to the root node of the tree
 * @index: the current assigned index to root node
 * @n: Number of nodes in the tree
 * Return: Returns boolean value
 */
int is_complete(const binary_tree_t *tree, int index, int n)
{
	if (!tree)
		return (1);
	if (index >= n)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, n) &&
			is_complete(tree->right, 2 * index + 2, n));
}


/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int n = count_node(tree);

	if (!tree)
		return (0);
	if (n == 0)
		return (1);

	return (is_complete(tree, 0, n));
}
