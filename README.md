# 0x1D. C - Binary trees
 Foundations > Low-level programming & Algorithm > Data structures and Algorithms


## Resources
Read or watch:

* [Binary tree (note the first line: Not to be confused with B-tree.)](https://en.wikipedia.org/wiki/Binary_tree)
* [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)
* [Tree Traversal](https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm)
* [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
* [Data structures: Binary Tree](https://www.youtube.com/watch?v=H5JubkIy_p8)

# Tasks

## 0. New node  [0-binary_tree_node.c]
  Write a function that creates a binary tree node
* Prototype: [binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);]
* Where parent is a pointer to the parent node of the node to create
* And value is the value to put in the new node
* When created, a node does not have any child
* Your function must return a pointer to the new node, or NULL on failure
> 0-binary_tree_node.c | ./0-node

## 1. Insert left  [1-binary_tree_insert_left.c]
  Write a function that inserts a node as the left-child of another node
* Prototype: [binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);]
* Where parent is a pointer to the node to insert the left-child in
* And value is the value to store in the new node
* Your function must return a pointer to the created node, or NULL on failure or if parent is NULL
* If parent already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left | ./1-left

## 2. Insert right  [2-binary_tree_insert_right.c]
  Write a function that inserts a node as the right-child of another node
* Prototype: [binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);]
* Where parent is a pointer to the node to insert the right-child in
* And value is the value to store in the new node
* Your function must return a pointer to the created node, or NULL on failure or if parent is NULL
* If parent already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right | ./2-right 

## 3. Delete  [3-binary_tree_delete.c]
  Write a function that deletes an entire binary tree
* Prototype: [void binary_tree_delete(binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to delete
* If tree is NULL, do nothing
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del

> valgrind ./3-del

## 4. Is leaf  [4-binary_tree_is_leaf.c]
  Write a function that checks if a node is a leaf
* Prototype: [int binary_tree_is_leaf(const binary_tree_t *node);]
* Where node is a pointer to the node to check
* Your function must return 1 if node is a leaf, otherwise 0
* If node is NULL, return 0
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf

> ./4-leaf

## 5. Is root  [5-binary_tree_is_root.c]
  Write a function that checks if a given node is a root
* Prototype: [int binary_tree_is_root(const binary_tree_t *node);]
* Where node is a pointer to the node to check
* Your function must return 1 if node is a root, otherwise 0
* If node is NULL, return 0
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root

> ./5-root

## 6. Pre-order traversal  [6-binary_tree_preorder.c]
  Write a function that goes through a binary tree using pre-order traversal
* Prototype: [void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));]
* Where tree is a pointer to the root node of the tree to traverse
* And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
* If tree or func is NULL, do nothing
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre | ./6-pre

## 7. In-order traversal  [7-binary_tree_inorder.c]
  Write a function that goes through a binary tree using in-order traversal
* Prototype: [void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));]
* Where tree is a pointer to the root node of the tree to traverse
* And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
* If tree or func is NULL, do nothing
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in | ./7-in

## 8. Post-order traversal  []
  Write a function that goes through a binary tree using post-order traversal
* Prototype: [void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));]
* Where tree is a pointer to the root node of the tree to traverse
* And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
* If tree or func is NULL, do nothing
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post | ./8-post

## 9. Height  [9-binary_tree_height.c]
  Write a function that measures the height of a binary tree
* Prototype: [size_t binary_tree_height(const binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to measure the height.
* If tree is NULL, your function must return 0
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height

> ./9-height

## 10. Depth  [10-binary_tree_depth.c]
  Write a function that measures the depth of a node in a binary tree
* Prototype: [size_t binary_tree_depth(const binary_tree_t *tree);]
* Where tree is a pointer to the node to measure the depth
* If tree is NULL, your function must return 0
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth

> ./10-depth

## 11. Size  [11-binary_tree_size.c]
  Write a function that measures the size of a binary tree
* Prototype: [size_t binary_tree_size(const binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to measure the size
* If tree is NULL, the function must return 0
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size

> ./11-size

## 12. Leaves  [12-binary_tree_leaves.c]
  Write a function that counts the leaves in a binary tree
* Prototype: [size_t binary_tree_leaves(const binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to count the number of leaves
* If tree is NULL, the function must return 0
* A NULL pointer is not a leaf
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves

> ./12-leaves

## 13. Nodes  [13-binary_tree_nodes.c]
  Write a function that counts the nodes with at least 1 child in a binary tree
* Prototype: [size_t binary_tree_nodes(const binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to count the number of nodes
* If tree is NULL, the function must return 0
* A NULL pointer is not a node
> gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes

> ./13-nodes

## 14. Balance factor  []
  Write a function that measures the balance factor of a binary tree
* Prototype: [int binary_tree_balance(const binary_tree_t *tree);]
* Where tree is a pointer to the root node of the tree to measure the balance factor
* If tree is NULL, return 0


