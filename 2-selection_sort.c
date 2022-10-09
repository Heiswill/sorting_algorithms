#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * selection_sort - Function that sorts an array of integers in
 * ascending order using selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_pos;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
		{
			tmp = array[i];
			array[i] = array[min_pos];
			array[min_pos] = tmp;
			print_array(array, size);
		}
	}
}
