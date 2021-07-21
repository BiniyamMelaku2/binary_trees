#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: height of tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t hleft = 0, hright = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
hleft = binary_tree_height(tree->left) + 1;
if (tree->right != NULL)
hright = binary_tree_height(tree->right) + 1;
if (hleft < hright)
return (hright);
return (hleft);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: balance factor otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int hleft = 0, hright = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
hleft = binary_tree_height(tree->left) + 1;
if (tree->right != NULL)
hright = binary_tree_height(tree->right) + 1;
return (hleft - hright);
}
