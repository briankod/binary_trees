#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if full, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_branch, right_branch;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_branch = binary_tree_is_full(tree->left);
	right_branch = binary_tree_is_full(tree->right);
	if (left_branch == 0 || right_branch == 0)
		return (0);
	return (1);
}
