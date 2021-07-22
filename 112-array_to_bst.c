#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * posn - traverses binry tree to position new node
 * @temp: root of the binary tree
 * @node: a new node
 * Return: a pointer to the root node
 */
bst_t *posn(bst_t *temp, bst_t *node)
{
bst_t *tmpcopy = NULL;
while (temp)
{
tmpcopy = temp;
if (node->n == temp->n)
break;
else if (node->n < temp->n)
temp = temp->left;
else
temp = temp->right;
}
return (tmpcopy);
}


/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: is a pointer to the first element of the array
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
bst_t *tree = NULL, *temp = NULL, *tmpcopy = NULL, *new = NULL;
size_t i = 0;
for (i = 0; i < size; i++)
{
new = malloc(sizeof(bst_t));
if (new == NULL)
return (NULL);
new->n = array[i];
new->left = NULL;
new->right = NULL;
if (tree == NULL)
{
new->parent = NULL;
tree = new;
}
else
{
tmpcopy = tree;
temp = posn(tmpcopy, new);
if (new->n == temp->n)
{
free(new);
continue;
}
else if (temp->n > new->n)
{
temp->left = new;
new->parent = temp;
}
else
{
temp->right = new;
new->parent = temp;
}
}
}
return (tree);
}
