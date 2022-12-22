#include "binary_trees.h"


/**
* heap_insert -  Creates a binary tree node
* @root: double pointer to the root node of the Heap
* @value: the value store in the node to be inserted
* Return: pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t level = 0, i, temp;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *) *root, value);
		return (*root);
	}
	level = binary_tree_height(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *) _insert((binary_tree_t *) *root, i, value);
		if (node != NULL)
			break;
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: the node to check
 * Return: 1:0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_depth - The depth of the tree
 * @tree: a binary tree
 * Return: the depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	depth = binary_tree_depth(tree->parent) + 1;
	return (depth);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a binary tree
 * Return: the height of a binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
* _insert - function to insert node
* @tree: pointer to tree
* @level: level to insert node
* @value: value of the new node
* Return: the node inserted
*/
binary_tree_t *_insert(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (binary_tree_is_leaf(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = _insert(tree->left, level, value);
	if (left == NULL)
		right = _insert(tree->right, level, value);
	else
		return (left);
	return (right);
}
