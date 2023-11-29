#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

if (tree == NULL)
return (0);

while (tree->parent != NULL)
{
depth++;
tree = tree->parent;
}

return (depth);
}
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
const binary_tree_t *temp1, *temp2;
size_t depth1, depth2;

if (!first || !second)
return (NULL);

temp1 = first;
temp2 = second;
depth1 = binary_tree_depth(temp1);
depth2 = binary_tree_depth(temp2);

while (depth1 > depth2)
{
temp1 = temp1->parent;
depth1--;
}

while (depth2 > depth1)
{
temp2 = temp2->parent;
depth2--;
}

while (temp1 && temp2)
{
if (temp1 == temp2)
return (binary_tree_t *)temp1;

temp1 = temp1->parent;
temp2 = temp2->parent;
}

return (NULL);
}

