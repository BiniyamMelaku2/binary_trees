#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * @node: a pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
if (node != NULL)
{
if (node->parent == NULL)
return (1);
else
return (0);
}
return (0);
}
