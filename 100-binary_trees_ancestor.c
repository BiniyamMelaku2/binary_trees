#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: depth of tree, otherwise 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;
if (tree == NULL)
return (0);
if (tree->parent != NULL)
depth = binary_tree_depth(tree->parent) + 1;
return (depth);
}


/**
 * binary_tree_depth - measures the depth of a binary tree
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: depth of tree, otherwise 0
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
size_t hfirst, hsecond;
binary_tree_t *fir = (binary_tree_t *)first;
binary_tree_t *sec = (binary_tree_t *)second;

if (first == NULL || second == NULL)
return (NULL);

hfirst = binary_tree_depth(first);
hsecond = binary_tree_depth(second);

for (; hfirst < hsecond; hsecond--)
sec = sec->parent;
for (; hsecond < hfirst; hfirst--)
fir = fir->parent;
while (fir && sec)
{
if (fir == sec)
return (fir);
fir = fir->parent;
sec = sec->parent;
}
return (NULL);
}

