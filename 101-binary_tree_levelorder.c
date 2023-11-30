#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If `tree` or `func` is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

const binary_tree_t **array = malloc(sizeof(binary_tree_t *));
size_t front = 0, rear = 0;
const binary_tree_t *current_node;

if (!array)
return;

array[rear] = tree;

while (rear < 10)
{
current_node = array[front];
front++;

if (current_node)
{
func(current_node->n);

/* Enqueue the left child */
if (current_node->left)
{
rear++;
array = realloc(array, (rear + 1) * sizeof(binary_tree_t *));
array[rear] = current_node->left;
}

/* Enqueue the right child */
if (current_node->right)
{
rear++;
array = realloc(array, (rear + 1) * sizeof(binary_tree_t *));
array[rear] = current_node->right;
}
}
}

free(array);
}

