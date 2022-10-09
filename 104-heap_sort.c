#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void heapify(int *array, size_t size, size_t i);
/**
 * heap_sort - Sorts anarray of integers in ascending order
 * using the heap sort algorithm.
 * @array: Integer array.
 * @size: Array size.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i >= 1; i--)
		heapify(array, size, i);
}

/**
 * heapify - Check code.
 * @array: array.
 * @size: Array size.
 * @i: index.
 */
void heapify(int *array, size_t size, size_t i)
{
	int tmp;
	size_t largest = i;
	size_t l = 2 * i;
	size_t r = (2 * i) + 1;

	if (l <= size && array[l] > array[largest])
		largest = l;
	if (r <= size && array[r] > array[largest])
		largest = r;
	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		heapify(array, largest, size);
	}
}
