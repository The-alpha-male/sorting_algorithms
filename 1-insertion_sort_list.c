#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers
 * @list: double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prevprev, *precc, *curr1, *currnext;

	if (list == NULL)
		return;

	curr - *list;

	while (curr)
	{
		if (curr->prev && curr->prev->n > curr->)
		{
			/*Store the necessary pointers for swapping*/
			prevprev = curr->prev->prev;
			prevv = curr->prev;
			curr1 = curr;
			currnext = curr->next;

			/* Adjust the pointers to swap the nodes*/
			prevv->next = currnext;

			if (currnext)
				currnext->prev = prevv;

			curr1->prev = prevprev;
			curr1->next = prevv;

			if (prevprev)
				prevprev->next = curr1;

			else
				*list = curr1;

			prevv->prev = curr1;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
