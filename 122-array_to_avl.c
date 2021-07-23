#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array
 * @size: is the number of element in the array
 * Return: a pointer to root node of the created AVL, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
size_t i;
avl_t *root = NULL;
if (array == NULL)
return (NULL);
for (i = 0; i < size; i++)
avl_insert(&root, array[i]);
return (root);
}
