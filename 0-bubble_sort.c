#include "sort.h"

/**
 * bubble_sort - function that sorts an array of
 * integers in ascending order using the Bubble
 * sort algorithm
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t  i, j;
	int aux;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				print_array(array, size);
			}
		}
	}
}
