#include "binary_trees.h"

/**
 * isBST - function to check if a binary tree is a BST
 * @tree: a pointer to the root node of the tree to check
 * @min: current minimum value
 * @max: current maximun value
 * Return: 1 if BST, otherwise 0
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return ((isBST(tree->right, tree->n, max)) &&
			(isBST(tree->left, min, tree->n)));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid Binary
 * Search Tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBST(tree, INT_MIN, INT_MAX));
}
