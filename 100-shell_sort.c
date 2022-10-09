#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of @array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (size < 2)
		return;

	for (gap = size/2; gap > 0; gap /=2)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}

}
