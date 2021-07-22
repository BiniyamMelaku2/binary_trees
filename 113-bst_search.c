#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: a pointer to the node containing a value, else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *temp = NULL;
if (tree == NULL)
return (NULL);
if (tree->n == value)
return ((bst_t *)tree);
else if (tree->n > value)
temp = bst_search(tree->left, value);
else
temp = bst_search(tree->right, value);
return (temp);
}
