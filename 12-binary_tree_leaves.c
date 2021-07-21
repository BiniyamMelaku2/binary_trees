#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: the leaves count of tree, otherwise 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t lleft = 0, lright = 0;
if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);
lleft = binary_tree_leaves(tree->left);
lright = binary_tree_leaves(tree->right);
return (lleft + lright);
}
