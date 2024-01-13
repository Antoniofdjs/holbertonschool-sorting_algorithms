#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using the insertion sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current_node, *prev_node;

	if (!list || !(*list))
		return;

	for (current_node = (*list)->next; current_node;
			current_node = current_node->next)
	{
		while (current_node->prev && current_node->prev->n > current_node->n)
		{
			prev_node = current_node->prev;

			current_node->prev = prev_node->prev;
			prev_node->prev = current_node;
			prev_node->next = current_node->next;
			current_node->next = prev_node;

			if (current_node->prev)
				current_node->prev->next = current_node;
			else
				*list = current_node;

			if (prev_node->next)
				prev_node->next->prev = prev_node;

			print_list(*list);
		}
	}
}
