#include "sort.h"

/**
 *insertion_sort_list - function that sorts a doubly
 *linked list of integers in ascending order using the
 *Insertion sort algorithm
 *@list: The list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *change, *next_aux;

	if (list == NULL || *list == NULL)
		return;
	change = (*list)->next;
	while (change != NULL)
	{
		next_aux = change->next;
		while (change->prev != NULL && change->prev->n > change->n)
		{
			change->prev->next = change->next;
			if (change->next != NULL)
				change->next->prev = change->prev;
			change->next = change->prev;
			change->prev = change->next->prev;
			change->next->prev = change;
			if (change->prev == NULL)
				*list = change;
			else
				change->prev->next = change;
			print_list(*list);
		}
		change = next_aux;
	}
}
