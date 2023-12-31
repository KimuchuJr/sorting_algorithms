#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending order using
 * the selection sort algorithm
 *
 * @array: the integer array to sort
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
        int temp;

	if (!array || size < 2)
		return;


	for (i = 0; i < size - 1; ++i)
	{
		minIndex = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
		{
			temp = array[minIndex];
			array[minIndex] = array[i];
			array[i] = temp;
		}
	}
}

