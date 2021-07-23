#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <stdbool.h>

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

/**
 * swap - swaps two nodes
 * @node: the first node
 * @new: the second node
 * Return: a pointer to the root node after swap
 */
bst_t *swap(bst_t *node, bst_t *new)
{
bst_t *temp = NULL;
bool left_child = false;
if (node->parent)
left_child = node->parent->left == node;
if (new->parent && new->parent != node)
new->parent->left = NULL;
new->parent = node->parent;
if (node->parent)
{
if (left_child)
node->parent->left = new;
else
node->parent->right = new;
}
if (node->left != new)
{
new->left = node->left;
node->left->parent = new;
}
if (node->right && node->right != new)
{
new->right = node->right;
node->right->parent = new;
}
temp = new;
while (temp->parent)
temp = temp->parent;
free(node);
return (temp);
}



/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing
 */
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *temp = NULL, *node = NULL;
bool left_child = false;
if (root == NULL)
return (NULL);
node = bst_search(root, value);
if (node == NULL)
return (NULL);
if (node->parent != NULL)
left_child = node->parent->left == node;
if (!node->right && !node->left) /* node has no child */
{
if (!node->parent)
{
free(node);
return (NULL);
}
if (left_child)
node->parent->left = NULL;
else
node->parent->right = NULL;
temp = node->parent;
while (temp->parent)
temp = temp->parent;
free(node);
return (temp);
}
if (!node->right) /* node has no right child */
return (swap(node, node->left));
temp = node->right;
while (temp->left)
temp = temp->left;
return (swap(node, temp));
}
