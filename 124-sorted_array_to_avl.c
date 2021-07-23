#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * sort_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array
 * @start: start index
 * @end: stop index
 * @parent: a pointer to root node
 * Return: a pointer to the root AVL tree, or NULL on failure
 */
avl_t *sort_array_to_avl(int *array, int start, int end, avl_t *parent)
{
avl_t *new;
int mid;
if (start > end)
return (NULL);
mid = (start + end) / 2;
new = calloc(1, sizeof(avl_t));
if (new == NULL)
return (NULL);
new->n = array[mid];
new->parent = parent;
new->left = sort_array_to_avl(array, start, mid - 1, new);
new->right = sort_array_to_avl(array, mid + 1, end, new);
return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array
 * @size: is the number of element in the array
 * Return: a pointer to the root AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL)
return (NULL);
return (sort_array_to_avl(array, 0, size - 1, NULL));
}
