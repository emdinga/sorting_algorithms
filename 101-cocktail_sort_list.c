#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		temp = *list;
		while (temp->next != NULL)
		{
			if (temp->next != NULL)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		temp = temp->prev;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}while (swapped);
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a, *next_a, *prev_b, *next_b;

	if (a == NULL || b == NULL)
		return;
	prev_a = a->prev;
	next_a = a->next;
	prev_b = b->prev;
	next_b = b->next;

	if (prev_a != NULL)
		prev_a->next =b;
	else
		*list = b;
	if (next_b != NULL)
		next_b->prev = a;
	a->prev = prev_b;
	if (next_b != NULL)
		next_b->prev = a;
	a->prev = prev_b;
	a->next = next_b;
	b->prev = prev_a;
	b->next = a;
}
