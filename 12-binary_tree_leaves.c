#include "binary_trees.h"
#include "4-binary_tree_is_leaf.c"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves in the binary tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lLeaf, rLeaf;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	lLeaf = binary_tree_leaves(tree->left);
	rLeaf = binary_tree_leaves(tree->right);

	return (lLeaf + rLeaf);
}
