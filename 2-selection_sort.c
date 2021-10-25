#include "sort.h"

/**
 * selection_sort - function that sorts an array of
 * integers in ascending order using the Selection
 * sort algorithm
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int aux;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min == i)
			continue;
		aux = array[i];
		array[i] = array[min];
		array[min] = aux;
		print_array(array, size);
	}
}
