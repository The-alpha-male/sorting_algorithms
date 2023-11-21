#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to sort
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
    listint_t *tmp;
    int swapped = 1;

    if (list == NULL || *list == NULL)
        return;

    tmp = *list;
    while (swapped == 1)
    {
        swapped = 0;
        while (tmp->next != NULL)
        {
            if (tmp->n > tmp->next->n)
            {
                swap_nodes(tmp, tmp->next, list);
                swapped = 1;
            }
            else
                tmp = tmp->next;
        }
        if (swapped == 0)
            break;
        swapped = 0;
        while (tmp->prev != NULL)
        {
            if (tmp->n < tmp->prev->n)
            {
                swap_nodes(tmp->prev, tmp, list);
                swapped = 1;
            }
            else
                tmp = tmp->prev;
        }
    }
}
