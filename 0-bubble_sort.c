#include <unistd.h>
#include <stdlib.h>

/**
 * swap - Swaps two integers in an array.
 * @xp: First integer to swap.
 * @yp: Second integer to swap.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: The size of the array.
 */
void print_array(int *array, size_t size)
{
	char buffer[50];
	size_t i;
	int length;

	for (i = 0; i < size; i++)
	{
		length = sprintf(buffer, "%d ", array[i]);
		write(1, buffer, length);
	}
	write(1, "\n", 1);
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

