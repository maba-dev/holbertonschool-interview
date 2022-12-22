#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_node - creates a binary tree node
 * @parent: the parent of the binary tree
 * @value: the value of the binary tree node
 * Return: the binary tree node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
        binary_tree_t *racine = malloc(sizeof(*racine));


        if (racine == NULL)
                return (NULL);
        racine->n = value;
        racine->parent = parent;
        racine->left = NULL;
        racine->right = NULL;
        return (racine);
}