#include "sort.h"



/**
 * partition - method of sorting to find partition quick sort
 * @array: Array to be sorted.
 * @low: Low index of the partition.
 * @high: high index of aray
 * @size: size of array
 * Return: Return the index of the pivot after partitioning.
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int temp, pivot;
	int i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}

	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (i != j)
		print_array(array, size);
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



void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
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
