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
 * print_level - prints values in same level
 * @i: level of a node
 * @tree: is a pointer to the root node of the tree
 * @func: is a pointer to a function to call for each node
 */
void print_level(const binary_tree_t *tree, size_t i, void (*func)(int))
{
if (i == 1)
func(tree->n);
else if (i > 1)
{
print_level(tree->left, i - 1, func);
print_level(tree->right, i - 1, func);
}
}

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: is a pointer to the root node of the tree
 * @func: is a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
size_t i, height;
if (tree == NULL || func == NULL)
return;
height = binary_tree_height(tree);
for (i = 1; i <= height + 1; i++)
print_level(tree, i, func);
}
