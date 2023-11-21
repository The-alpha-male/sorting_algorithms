#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two subarrays of integers in ascending order
 * @array: array to sort
 * @left: left subarray
 * @right: right subarray
 * @left_size: size of left subarray
 * @right_size: size of right subarray
 *
 * Return: void
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size);

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t i, middle;

	if (array == NULL || size < 2)
		return;

	middle = size / 2;

	left = malloc(sizeof(int) * middle);
	right = malloc(sizeof(int) * (size - middle));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < middle; i++)
		left[i] = array[i];

	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);

	merge(array, left, right, middle, size - middle);

	free(left);
	free(right);
}

/**
 * merge - merges two subarrays of integers in ascending order
 * @array: array to sort
 * @left: left subarray
 * @right: right subarray
 * @left_size: size of left subarray
 * @right_size: size of right subarray
 *
 * Return: void
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
	size_t i, j, k;
	int *temp;

	temp = malloc(sizeof(int) * (left_size + right_size));

	if (temp == NULL)
		return;

	i = j = k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	free(temp);
}

