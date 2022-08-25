#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function that checks if a node is a leaf
 * @node: a pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}


/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height
 * If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_height(tree->left) !=
			binary_tree_height(tree->right))
		return (0);
	if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
		return (1);
	return (0);
}


/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	left_height = binary_tree_height(l);
	right_height = binary_tree_height(r);
	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
