#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @value: is the value to store in the node
 * @tree: is a double pointer to the root node of the BST
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *posn = NULL;
posn = *tree;
if (posn == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
while (posn != NULL)
{
if (posn->n > value)
{
if (posn->left == NULL)
{
posn->left = binary_tree_node(posn, value);
return (posn->left);
}
posn = posn->left;
}
else if (posn->n < value)
{
if (posn->right == NULL)
{
posn->right = binary_tree_node(posn, value);
return (posn->right);
}
posn = posn->right;
}
else if (posn->n == value)
return (NULL);
}
return (NULL);
}
