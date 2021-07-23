#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: height of tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t hleft = 0, hright = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
hleft = binary_tree_height(tree->left) + 1;
if (tree->right != NULL)
hright = binary_tree_height(tree->right) + 1;
if (hleft < hright)
return (hright);
return (hleft);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: balance factor otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int hleft = 0, hright = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
hleft = binary_tree_height(tree->left) + 1;
if (tree->right != NULL)
hright = binary_tree_height(tree->right) + 1;
return (hleft - hright);
}

/**
 * is_binary_tree_avl - checks if a binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_binary_tree_avl(const binary_tree_t *tree)
{
int bal;
if (tree == NULL)
return (1);
bal = binary_tree_balance(tree);
if (abs(bal) > 1)
return (0);
return (is_binary_tree_avl(tree->left) && is_binary_tree_avl(tree->right));
}


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_binary_tree_avl(tree));
}
