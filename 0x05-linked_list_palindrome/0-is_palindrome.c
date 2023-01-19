#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - function in C that checks if a list is a palindrome
 *
 * @head: node of list
 * Return: 1 if true or 0 if false
 */
int is_palindrome(listint_t **head)
{
    int length = 0;
    int tab[4352];
    int i;
    int j;
    listint_t *current_node = *head;

    if (*head == NULL || (current_node && !current_node->next))
        return (1);
    while (current_node)
    {
        tab[length] = current_node->n;
        current_node = current_node->next;
        length++;
    }
    j = length - 1;

    for (i = 0; i < length / 2; i++)
    {
        if (tab[i] == tab[j])
            j--;
        else
            return (0);
    }
    return (1);
}
