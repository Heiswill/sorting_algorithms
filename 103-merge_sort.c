#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort_recursion(int *array, size_t l, size_t r);
void merge_sorted_arrays(int *array, size_t l, size_t m, size_t r);

/**
 * merge_sort - Function that sorts an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_recursion(array, 0, size - 1);
}

/**
 * merge_sort_recursion - Check code.
 * @array: Integer array.
 * @l: leftmost index of divided array.
 * @r: righmost index of divided array.
 */
void merge_sort_recursion(int *array, size_t l, size_t r)
{
	size_t m;
	
	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort_recursion(array, l, m);
		merge_sort_recursion(array, m + 1, r);

		merge_sorted_arrays(array, l, m, r);
	}
}

/**
 * merge_sorted_arrays - Check code.
 * @array: integer array.
 * @l: left index.
 * @m: middle index.
 * @r: right index.
 */
void merge_sorted_arrays(int *array, size_t l, size_t m, size_t r)
{
        size_t left_length, right_length;
        int *tmpleft;
	int *tmpright;
        size_t i, j, k;

        left_length = m - l + 1;
        right_length = r - m;

	for (i = 0; i < left_length; i++)
		tmpleft[i] = array[l + i];
	for (i = 0; i < right_length; i++)
		tmpright[i] = array[m + 1 + i];
	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < left_length) &&
		    (j >= right_length) || tmpleft[i] <= tmpright[j])
		{
			array[k] = tmpleft[i];
			i++;
		}
		else
		{
			array[k] = tmpright[i];
			j++;
		}
	}
}
