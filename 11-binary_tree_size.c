#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size
 * If tree is NULL, return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_branch, right_branch;

	if (tree == NULL)
		return (0);
	left_branch = binary_tree_size(tree->left);
	right_branch = binary_tree_size(tree->right);
	return (left_branch + right_branch + 1);
}
