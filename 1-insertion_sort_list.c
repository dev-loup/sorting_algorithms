#include "sort.h"
/**
 * insertion_sort_list - Sort a dlinked list using bubble sort
 * @list: head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *runner, *keeper;

	if (!list || !*list || !(*list)->next)
		return;

	keeper = (*list)->next;
	runner = keeper;

	while (runner)
	{
		runner = runner->next;
		while (keeper->prev && keeper->n < keeper->prev->n)
		{
			keeper->prev->next = keeper->next;
			if (keeper->next)
				keeper->next->prev = keeper->prev;
			keeper->next = keeper->prev;
			keeper->prev = keeper->next->prev;
			keeper->next->prev = keeper;
			if (keeper->prev)
				keeper->prev->next = keeper;
			else
				*list = keeper;
			print_list(*list);
		}
		keeper = runner;
	}
}
