#include "sort.h"

/**
 * swap_int - swaps two elements in an array
 * @a: first element
 * @b: second element
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;
		if (min_index != i)
		{
			swap_int(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
