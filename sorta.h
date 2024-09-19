#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

/* Structures */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void quickSort(int *array, int low, int high, size_t size);
void swap(int *array, int *a, int *b, size_t size);
int partition(int *array, int start, int end, size_t size);
void print_merge(int *array, int *p1, int *p2, size_t size);
void merge_sort(int *array, size_t size);
void swap_nodes(int *array, size_t size, size_t indexA, size_t indexB);
void heapify(int *array, size_t size, size_t heapSize, size_t parentIndex);
void build_max_heap(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursive(char arr, int *array, size_t size, size_t i);
void merge_array(char arr, int *array, size_t size);
void order(char arr, int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
