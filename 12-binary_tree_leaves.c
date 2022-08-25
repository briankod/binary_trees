#include "binary_trees.h"

/**
 * binary_tree_leaves -  function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: count of leaves
 * If tree is NULL, return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_branch, right_branch;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_branch = binary_tree_leaves(tree->left);
	right_branch = binary_tree_leaves(tree->right);
	return (left_branch + right_branch);
}
