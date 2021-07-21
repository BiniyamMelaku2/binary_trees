#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child
 * @tree: is a pointer to the root node of the tree
 * Return: the nodes count of tree, otherwise 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t node = 0;
if (tree == NULL)
return (0);
node += binary_tree_nodes(tree->left);
node += binary_tree_nodes(tree->right);
if (tree->left != NULL || tree->right != NULL)
node++;
return (node);
}
