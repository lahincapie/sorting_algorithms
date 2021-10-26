#include "sort.h"

/**
 * shell_sort - function that sorts an array of
 * integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array to sort
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, slot = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (slot < size / 3)
		slot = slot * 3 + 1;

	while (slot > 0)
	{
		for (i = slot; i < size; i++)
		{
			insert = array[i];
			for (j = i; j >= slot && array[j - slot] > insert; j = j - slot)
				array[j] = array[j - slot];
			array[j] = insert;
		}
		slot = (slot - 1) / 3;
		print_array(array, size);
	}
}
