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
 * isAVL - function to check if a binary tree is a AVL
 * @tree: A pointer to the root node of the tree to check
 * @min: current minimum value
 * @max: current maximum value
 * Return: 1 if AVL, otherwise 0
 */
int isAVL(const binary_tree_t *tree, int min, int max)
{
	size_t left_height, right_height, diff;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	left_height = binary_tree_height_2(tree->left);
	right_height = binary_tree_height_2(tree->right);
	if (left_height > right_height)
		diff = left_height - right_height;
	else
		diff = right_height - left_height;
	if (diff > 1)
		return (0);
	return ((isAVL(tree->right, tree->n, max)) &&
			(isAVL(tree->left, min, tree->n)));
}


/**
 * binary_tree_is_avl - function that checks if a binary tree is a
 * valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isAVL(tree, INT_MIN, INT_MAX));
}
