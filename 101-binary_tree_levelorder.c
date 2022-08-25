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
 * binary_tree_level - function that finds nodes at a given level
 * @tree: a pointer to the root node of the tree
 * @level: the given level
 * @func: a pointer to a function to call for each node.
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t level,
						void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}


/**
 * binary_tree_levelorder - function that goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height_2(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
