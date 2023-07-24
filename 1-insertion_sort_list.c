#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using
 * the insertion sort algorithm
 *
 * @list: the doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *sorted = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;


	while (*list)
	{
		listint_t *current = *list;
		*list = (*list)->next;

		if (!sorted || current->n < sorted->n)
		{
			current->prev = NULL;
			current->next = sorted;
			if (sorted)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp->next && temp->next->n < current->n)
				temp = temp->next;

			current->prev = temp;
			current->next = temp->next;

			if (temp->next)
				temp->next->prev = current;

			temp->next = current;
		}

		print_list(sorted);
	}

	*list = sorted;
}

