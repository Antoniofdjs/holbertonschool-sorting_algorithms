#include "sort.h"

/**
 * bubble_sort- sorts array ints ascending order
 * @array: array unsorted of ints
 * @size: size of array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swap = 1;
	int temp;

	while (swap != 0)
	{
		swap = 0; /* reset swap switch */
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = 1; /* on switch for swapp */
				temp = array[i + 1]; /* lower num stored in temp */
				array[i + 1] = array[i]; /* big num is stored in next index */
				array[i] = temp; /* low number is stored in index */
				print_array(array, size);
			}
		}
	}
}

