#include "sort.h"



/**
 * partition - method of sorting to find partition quick sort
 * @array: Array to be sorted.
 * @low: Low index of the partition.
 * @high: high index of aray
 * @size: size of array
 * Return: Return the index of the pivot after partitioning.
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int temp, pivot;
	size_t i, j, idx_pivot = low;

	pivot = array[low];
	i = low;
	j = high;

	while (i < j)
	{
		while (array[j] >= pivot && j > low)
			j--;

		if (i < j)
		{
			if (array[i] == pivot)
				idx_pivot = j;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++;
			print_array(array, size);
		}
	}
	if (idx_pivot != i && i != j)
	{
		temp = array[i];
		array[i] = array[idx_pivot];
		array[idx_pivot] = temp;
		print_array(array, size);
	}
	return (i);
}


/**
 * quick_sort_recursion - Recursive function for quick sort.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: Size of the array.
 */



void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}


/**
 * quick_sort- sorts array ints quick method
 * @array: array unsorted of ints
 * @size: size of array
 *
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
