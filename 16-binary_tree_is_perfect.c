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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree
 * Return: 1 for perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t perf = 1, height, size;
if (tree == NULL)
return (0);
height = binary_tree_height(tree);
size = binary_tree_size(tree);
while (height + 1 > 0)
{
perf *= 2;
height--;
}
perf--;
if (perf == size)
return (1);
return (0);
}
