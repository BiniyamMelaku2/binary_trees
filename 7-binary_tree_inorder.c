#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using inorder traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;
if (tree->left != NULL)
{
binary_tree_inorder(tree->left, func);
func(tree->n);
}
if (tree->right != NULL)
{
func(tree->n);
binary_tree_inorder(tree->right, func);
func(tree->n);
}
}
