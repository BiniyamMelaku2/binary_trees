#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: the size of tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t hleft = 0, hright = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
hleft = binary_tree_size(tree->left);
if (tree->right != NULL)
hright = binary_tree_size(tree->right);
return (hleft + hright + 1);
}
