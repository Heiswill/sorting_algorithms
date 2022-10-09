#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void quicksort_recursion(int array[], size_t lo, size_t hi);
int partition(int array[], size_t lo, size_t hi);

/**
 * swap - Swap two integers in an array.
 * @x: Pointer to int x.
 * @y: Pointer to int y.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * quick_sort - Function that sort an array of integers in
 * ascending order using the quick sort algorithm.
 * @array: Array of integers.
 * @size: length of @array.
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1);
}

/**
 * quicksort_recursion - Recursive divide && conquer algorithm.
 * @lo: First index -> 0.
 * @hi: last index.
 */
void quicksort_recursion(int array[], size_t lo, size_t hi)
{
	int pivot_index = partition(array, lo, hi);
	quicksort_recursion(array, lo, pivot_index - 1);
	quicksort_recursion(array, pivot_index + 1, hi);
}

/**
 * partition - Get pivot index.
 * @lo: index 0.
 * @hi: last index value.
 */
int partition(int array[], size_t lo, size_t hi)
{
	int pivot_value = array[hi];
	size_t i, j = lo;

	for (; j < hi; j++)
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	swap(&array[i], &array[hi]);

	return (i);
}
