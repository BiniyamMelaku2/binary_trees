#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * balance_left - performs balancing left side of AVL tree
 * @node: a pointer to node to get rebalanced
 * Return: a pointer to the root node after balance
 */
avl_t *balance_left(avl_t *node)
{
avl_t *a, *b, *c;
c = node;
b = c->left;
if (b == NULL)
return (NULL);
a = binary_tree_balance(b) < 0 ? b->right : b->left;
if (a == NULL)
return (NULL);
if (a == b->left)
return (binary_tree_rotate_right(c));
binary_tree_rotate_left(b);
return (binary_tree_rotate_right(c));
}


/**
 * rebalance - performs rebalancing of AVL tree
 * @tree: is a double pointer to the root node of the AVL tree
 * @node: a pointer to node to get rebalanced
 * Return: a pointer to the root node after rebalance
 */
avl_t *rebalance(avl_t *node, avl_t **tree)
{
avl_t *tmp, *root, *a, *b, *c, *ret = NULL;
int bal;
tmp = node;
while (tmp)
{
bal = binary_tree_balance(tmp);
if (bal > 1)
{
root = balance_left(tmp);
if (root)
*tree = root;
}
else if (bal < -1)
{
c = tmp;
b = c->right;
if (b)
{
a = binary_tree_balance(b) < 0 ? b->right : b->left;
if (a)
{
if (a == b->right)
ret = binary_tree_rotate_left(c);
else
{
binary_tree_rotate_right(b);
ret = binary_tree_rotate_left(c);
}
}
}
if (ret)
*tree = ret;
}
tmp = tmp->parent;
}
return (node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: is a double pointer to the root node of the AVL tree
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *avl, *node;
if (tree == NULL)
return (NULL);
avl = calloc(1, sizeof(avl_t));
if (avl == NULL)
return (NULL);
avl->n = value;
if (*tree == NULL)
return (*tree = avl);
node = *tree;
while (node)
{
if (value == node->n)
return (free(avl), NULL);
if (value < node->n)
{
if (node->left == NULL)
{
avl->parent = node;
node->left = avl;
return (rebalance(node->left, tree));
}
node = node->left;
}
else
{
if (node->right == NULL)
{
avl->parent = node;
node->right = avl;
return (rebalance(node->right, tree));
}
node = node->right;
}
}
return (free(avl), NULL);
}
