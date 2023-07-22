#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		sorted = current;
		current = current->next;
		while (sorted->prev && sorted->n < sorted->prev->n)
		{
			temp = sorted->prev;
			sorted->prev = temp->prev;
			if (temp->)
				temp->prev->next = sorted;
			temp->next = sorted->next;
			if (sorted->next)
				sorted->next->prev = temp;
			sorted->next = temp;
			temp->prev = sorted;
			if (!sorted->prev)
				*list = sorted;
			print_list(*list);
		}
	}
}
