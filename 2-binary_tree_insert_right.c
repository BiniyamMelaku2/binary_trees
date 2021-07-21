#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new_node = NULL;
if (parent == NULL)
return (NULL);
new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
return (NULL);
if (parent->right != NULL)
{
new_node->right = parent->right;
parent->right->parent = new_node;
}
else
new_node->right = NULL;

new_node->n = value;
new_node->left = NULL;
parent->right = new_node;
new_node->parent = parent;
return (new_node);
}
