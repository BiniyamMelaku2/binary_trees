#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>


/**
 * is_bst - checks binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree
 * @min: smaller value of node
 * @max: larger value of node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);
if (tree->n >= max || tree->n <= min)
return (0);
return ((is_bst(tree->left, min, tree->n)) &&
	(is_bst(tree->right, tree->n, max)));
}

/**
 * binary_tree_is_bst - checks for a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_bst(tree, INT_MIN, INT_MAX));
}
