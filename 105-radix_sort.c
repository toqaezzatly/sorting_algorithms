#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

#define BASE 10
#define WIDTH 3

/**
 * counting_sort - Separate function for counting sort.
 * @array: array to be sorted.
 * @size: Number of elements in the array
 * @d: digit to be sorted.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size, int d)
{
	int count[BASE] = {0};
	size_t i, j;
	int *output = malloc(sizeof(int) * size);

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / d) % BASE]++;

	for (i = 1; i < BASE; i++)
		count[i] += count[i - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count[(array[j] / d) % BASE] - 1] = array[j];
		count[(array[j] / d) % BASE]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - sorts array of int in ascending order using Radix sort
 * @array: array to be sorted.
 * @size: Number of elements in the array
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max_value = 0;
	int exp = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	while (max_value / exp > 0)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
		exp *= BASE;
	}
}
