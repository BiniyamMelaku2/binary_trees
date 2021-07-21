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
 * check_complete - checks binary tree is complete
 * @tree: is a pointer to the root node of the tree
 * @index: level of index of a node
 * @size: number of nodes in a binary tree
 * Return: 1 for complete, otherwise 0
 */

int check_complete(const binary_tree_t *tree, size_t index, size_t size)
{
if (tree == NULL)
return (1);
if (index >= size)
return (0);
return (check_complete(tree->left, index * 2 + 1, size) &&
	check_complete(tree->right, index * 2 + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree
 * Return: 1 for complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
size_t size, index = 0;
if (tree == NULL)
return (0);
size = binary_tree_size(tree);
return (check_complete(tree, index, size));
}
