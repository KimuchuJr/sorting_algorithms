#include <stdio.h>
#include <stddef.h>
#include "sort.h"

void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *array, int index_1, int index_2, size_t size);

/**
 * quick_sort - sort an array of integers using the quick sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - implementation of quicksort algorithm with Lomuto partition
 *
 * @array: array to sort
 * @low: lowest index of subarray to sort
 * @high: highest index of subarray to sort
 * @size: size of the array
 *
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 *
 * @array: array to partition
 * @low: lowest index of subarray to sort
 * @high: highest index of subarray to sort
 * @size: size of the array
 *
 * Return: the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(array, i + 1, high, size);
	}

	return i + 1;
}

/**
 * swap - swaps two elements of an array
 *
 * @array: array containing the elements to swap
 * @index_1: index of first element
 * @index_2: index of second element
 * @size: size of array
 *
 */
void swap(int *array, int index_1, int index_2, size_t size)
{
	int temp;

	temp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = temp;
	print_array(array, size);
}

