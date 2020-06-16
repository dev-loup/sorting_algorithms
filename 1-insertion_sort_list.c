#include "sort.h"
/**
 * insertion_sort_list - Sort a dlinked list using bubble sort
 * @list: head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *runner = *list, *insert, *backrun;

	while (runner->next)
	{
		if (runner->next->n < runner->n)
		{
			insert = extract_node(&runner);
			backrun = runner;
			while (backrun->prev)
			{
				if (backrun->n < insert->n)
				{
					insert->next = backrun->next;
					insert->prev = backrun;
					backrun->next = insert;
					insert->next->prev = insert;
					break;
				}
				backrun = backrun->prev;
			}
			if (!backrun->prev)
			{
				insert->next = *list;
				insert->prev = *list;
				*list = insert;
			}
			print_list(*list);
		}
		else
			runner = runner->next;
	}
}
