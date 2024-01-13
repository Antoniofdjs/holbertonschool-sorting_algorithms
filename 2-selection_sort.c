#include "sort.h"

/**
 * selection_sort- sorts array ints ascending order
 * @array: array unsorted of ints
 * @size: size of array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;
	size_t index_min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i]; /* suppose i is always min when starting */
		index_min = i;
		for (j = i + 1; j < size; j++) /* start one index over and iterate all */
		{
			if (min > array[j])
			{
				min = array[j]; /* save new min */
				index_min = j; /* remember index we found min */
			}
		}
		if (index_min != i) /* if no new min found, indx_min = i, wont execute */
		{
			array[index_min] = array[i]; /* switch value where indx min was found*/
			array[i] = min; /* min set to lowest position in array available */
			print_array(array, size);
		}
	}
}
