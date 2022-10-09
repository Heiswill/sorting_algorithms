#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the counting sort algorithm.
 * @array: Array of integers.
 * @size: sizeof @array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *b;
	int max = array[0];
	int j;
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * size);
	b = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		++count[array[i]];
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	for (i = size - 1; i <= size; i--)
	{
		b[--count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = b[i];
	free(count);
	free(b);
}
