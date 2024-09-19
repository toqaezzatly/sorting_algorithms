#include "sort.h"
#include <stdlib.h>

void build_max_heap(int *array, size_t heapSize);
void heapify(int *array, size_t size, size_t heapSize, size_t parentIndex);
void swap_nodes(int *array, size_t size, size_t indexA, size_t indexB);

/**
 * heap_sort - Sorts an array of numbers using the heap method
 *
 * @array: array to sort
 * @size: length of array
 *
 */
void heap_sort(int *array, size_t size) {
	size_t heapSize;

	if (!array || size <= 1)
		return;

	build_max_heap(array, size);
	for (heapSize = size - 1; heapSize > 1; heapSize--)
	{
		swap_nodes(array, size, 0, heapSize);
		heapify(array, size, heapSize, 0);
	}
	swap_nodes(array, size, 0, heapSize);
}

/**
 * build_max_heap - heapifies an unsorted array
 *
 * @array: array to heapify
 * @size: length of array
 *
 */
void build_max_heap(int *array, size_t size) {
	int nodeIndex;

	for (nodeIndex = size / 2 - 1; nodeIndex >= 0; nodeIndex--)
		heapify(array, size, size, nodeIndex);
}

/**
 * heapify - heapifies a node and its children
 * and recursively sifts smaller values down
 *
 * @array: entire array
 * @size: array size
 * @heapSize: size of heap within array
 * @parentIndex: index of parent node
 *
 */
void heapify(int *array, size_t size, size_t heapSize, size_t parentIndex) {
	size_t leftNode = parentIndex * 2 + 1;
	size_t rightNode = leftNode + 1;
	size_t largest = parentIndex;

	if (leftNode <= heapSize - 1
			&& array[leftNode] > array[largest])
		largest = leftNode;

	if (rightNode <= heapSize - 1
			&& array[rightNode] > array[largest])
		largest = rightNode;

	if (largest != parentIndex)
	{
		swap_nodes(array, size, largest, parentIndex);
		heapify(array, size, heapSize, largest);
	}
}

/**
 * swap_nodes - Swaps two values in an int array
 *
 * @array: array of ints
 * @size: array size
 * @indexA: first value to swap
 * @indexB: second value to swap
 *
 */
void swap_nodes(int *array, size_t size, size_t indexA, size_t indexB) {
	int temp = array[indexA];

	array[indexA] = array[indexB];
	array[indexB] = temp;
	print_array(array, size);
}
