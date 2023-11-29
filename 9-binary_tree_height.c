#include "binary_trees.h"

/**
 
 * binary_tree_height - Measures the height of a binary tree

 * @tree: Pointer to the root node of the tree to measure the height

 * Return: Height of the binary tree, 0 if tree is NULL

*/

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t lheight, rheight;

if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (0);
lheight = binary_tree_height(tree->left);
rheight = binary_tree_height(tree->right);

if (lheight > rheight)
return (lheight + 1);
return (rheight + 1);
}
