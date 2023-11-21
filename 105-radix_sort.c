#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *count, *output;
	int max = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < (size_t)(max + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < (size_t)(max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

