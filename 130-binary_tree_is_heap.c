#include "binary_trees.h"

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
	left_branch = binary_tree_height(tree->left);
	right_branch = binary_tree_height(tree->right);
	return (left_branch - right_branch);
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
 * binary_tree_is_heap - function that checks if a binary tree is a valid
 * Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bal_factor;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	bal_factor = binary_tree_balance(tree);
	if (bal_factor == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (bal_factor == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
