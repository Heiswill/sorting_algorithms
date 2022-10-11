#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
void countSort(int *array, size_t, int pos);

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the radixsort algorithm.
 * @array: Integer array.
 * @size: Size of @array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0];
	int pos;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (pos = 1; (max / pos) > 0; pos *= 10)
		countSort(array, size, pos);
}

/**
 * countSort - Implement count sort.
 * @array: array.
 * @size: array size.
 * @pos: key.
 */
void countSort(int *array, size_t size, int pos)
{
	int count[10] = {0};
	size_t i;
	int *b = malloc(sizeof(int) * size);
	int max = array[0];
	int j;

	for (i = 1; i < size; i++)
        {
                if (array[i] > max)
                        max = array[i];
        }
	for (i = 0; i < size; i++)
		++count[(array[i] / pos) % 10];
	for (j = 1; j <= max; j++)
		count[j] = count[j] + count[j - 1];
	for (i = size - 1; i <= size; i--)
		b[--count[(array[i] / pos) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = b[i];
}
