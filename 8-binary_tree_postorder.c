#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses tree using post-order
 * @tree: a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;
if (tree->left != NULL)
binary_tree_postorder(tree->left, func);
if (tree->right != NULL)
binary_tree_postorder(tree->right, func);
func(tree->n);
}
