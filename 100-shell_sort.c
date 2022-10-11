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
	size_t gap = 1;
	size_t i, j;

	if (size < 2)
		return;
	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			while (i >= gap && array[i - gap] > array[i])
			{
				array[i] = array[i - gap];
				i = i - gap;
			}
			array[i] = array[j];
			print_array(array, size);
		}
		gap = gap / 3;
	}
}
