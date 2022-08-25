#include "binary_trees.h"

/**
 * findMinimum - Helper function to find minimum value node in a given BST
 * @root: a pointer to the root node of the tree
 * Return: minimum value node
 */
bst_t *findMinimum(bst_t *root)
{
	while (root->left)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (root == NULL)
		return (NULL);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		if (root->n < value)
			root->right = bst_remove(root->right, value);
		else
		{
			if (root->left && root->right)
			{
				tmp = findMinimum(root->right);
				root->n = tmp->n;
				root->right = bst_remove(root->right, tmp->n);
			}
			else
			{
				if (root->left == NULL && root->right == NULL)
				{
					free(root);
					return (NULL);
				}
				tmp = root;
				if (root->left == NULL)
					root = root->right;
				else
					if (root->right == NULL)
						root = root->left;
				if (tmp->parent->left == tmp)
					tmp->parent->left = root;
				else
					tmp->parent->right = root;
				root->parent = tmp->parent;
				free(tmp);
			}
		}
	return (root);
}
