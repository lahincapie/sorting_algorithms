#include <stdio.h>
#include "sort.h"

/**
 * partition - finds the partition for the quicksort
 * @array: array to sort
 * @lowest_index: lowest index of the partition to sort
 * @highest_index: highest index of the partition to sort
 * @size: size of the array
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lowest_index, ssize_t highest_index, size_t size)
{
	ssize_t i, j;
	int aux, pivot;
	pivot = array[highest_index];
	i = lowest_index - 1;
	for (j = lowest_index; j < highest_index; j++)
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
	if (array[highest_index] < array[i + 1])
	{
		aux = array[i + 1];
		array[i + 1] = array[highest_index];
		array[highest_index] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lowest_index: lowest index of the partition to sort
 * @highest_index: highest index of the partition to sort
 * @size: size of the array
 */
void quicksort(int *array, ssize_t lowest_index, ssize_t highest_index, size_t size)
{
	ssize_t pivot;
	if (lowest_index < highest_index)
	{
		pivot = partition(array, lowest_index, highest_index, size);
		quicksort(array, lowest_index, pivot - 1, size);
		quicksort(array, pivot + 1, highest_index, size);
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
