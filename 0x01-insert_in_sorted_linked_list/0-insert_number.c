#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head node of list
 * @number: value of node to insert
 * Return: new_node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
    listint_t *current_node;


	current_node = *head;
	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || (*head)->n > new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
        return (new_node);
	}
	while (current_node->next != NULL && current_node->next->n < new_node->n)
	{
		current_node = current_node->next;
	}
	new_node->next = current_node->next;
	current_node->next = new_node;
	return (new_node);
}
