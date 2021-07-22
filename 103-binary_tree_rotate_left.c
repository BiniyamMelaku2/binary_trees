#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *temp = NULL;
if (tree == NULL)
return (tree);
temp = tree->right;
temp->parent = tree->parent;
if (temp->left != NULL)
{
tree->right = temp->left;
temp->left->parent = tree;
}
else
tree->right = NULL;
temp->left = tree;
tree->parent = temp;
return (temp);
}

