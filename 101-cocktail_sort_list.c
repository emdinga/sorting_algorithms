#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *a;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				a = head;
			       swap_nodes(&a, list);
			       print_list(*list);
			       head = a;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				a = head->prev;
				swap_nodes(&a, list);
				print_list(*list);
				head = a->next;
			}
			c--;
			head = head->prev;
		}
	}
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @node: First node to swap
 */
void swap_nodes(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;

}
