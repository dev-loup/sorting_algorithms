#include "sort.h"
/**
 * insertion_sort_list - Sort a dlinked list using bubble sort
 * @list: head of the list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *runner = *list;
	listint_t *insert;
	listint_t *backrun;

	while (runner->next)
    {
		if (runner->next->n < runner->n)
		{
			printf("i got you %i\n", runner->next->n);
			insert = runner->next;
			if (insert->next)
			{
				runner->next = insert->next;
				insert->next->prev = runner;
			}
			else
			{
				runner->next = NULL;
			}
			if (runner->prev)
			{
				backrun = runner->prev;
				while (backrun->prev)
				{
					if (backrun->n < insert->n)
					{
						break;
					}
					backrun = backrun->prev;
				}
				if (backrun->n > insert->n)
				{
					insert->prev = *list;
					insert->next = backrun;
					*list = insert;
				}
				else
				{
					insert->prev = backrun;
					insert->next = backrun->next;
					backrun->next = insert;
					insert->next->prev = insert;
				}
			}			
		}
		else
		{
			runner = runner->next;
		}
	}
}