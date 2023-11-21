#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
    size_t i, j, gap = 1;
    int tmp;

    if (array == NULL || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            j = i;
            while (j > gap - 1 && array[j - gap] >= tmp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        print_array(array, size);
        gap = (gap - 1) / 3;
    }
}
