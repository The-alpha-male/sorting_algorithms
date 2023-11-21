<<<<<<< HEAD
#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
=======
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
>>>>>>> cdf74bc02d64c2112c5cd66e6645800e67690753
	{
		if (array[i] > max)
			max = array[i];
	}

<<<<<<< HEAD
	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
=======
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

>>>>>>> cdf74bc02d64c2112c5cd66e6645800e67690753
