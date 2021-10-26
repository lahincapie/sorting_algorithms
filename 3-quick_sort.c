#include <stdio.h>
#include "sort.h"

/**
 * partition - finds the partition for the quicksort
 * @array: array to sort
 * @li: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t li, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int aux, pivot;

	pivot = array[hi];
	i = li - 1;

	for (j = li; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		aux = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @li: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 */
void quicksort(int *array, ssize_t li, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (li < hi)
	{
		pivot = partition(array, li, hi, size);
		quicksort(array, li, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
