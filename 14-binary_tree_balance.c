#include "binary_trees.h"

/**
 * binary_tree_height_2 - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height
 * If tree is NULL, return 0
 */
size_t binary_tree_height_2(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height_2(tree->left);
	right_height = binary_tree_height_2(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_balance - function that measures the balance factor of
 * a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_branch, right_branch;

	if (tree == NULL)
		return (0);
	left_branch = binary_tree_height_2(tree->left);
	right_branch = binary_tree_height_2(tree->right);
	return (left_branch - right_branch);
}
