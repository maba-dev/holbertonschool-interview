#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located or NULL
 */


skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *current, *prev;

	if (!list)
		return (NULL);

	current = list, prev = list;

	while (current && current->next && (current->n) < value)
	{
		prev = current;

		if (current->express)
		{
			current = current->express;

			printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);
		}
		else
			while (current->next)
				current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);

	for (i = prev->index;
			i <= (current->index) && (prev->n <= value);
			i++, prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, prev->n);
		if (prev && (prev->n) == value)
			return (prev);
	}

	if (prev)
		printf("Value checked at index [%lu] = [%d]\n", i, prev->n);

	return (NULL);
}
