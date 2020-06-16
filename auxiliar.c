#include "sort.h"
/**
 * insertion_sort_list - Sort a dlinked list using bubble sort
 * @list: head of the list
 */

listint_t *extract_node(listint_t **runner)
{
    listint_t *insert;

	insert = (*runner)->next;
	if (insert->next)
	{
		(*runner)->next = insert->next;
		insert->next->prev = (*runner);
	}
	else
	{
		(*runner)->next = NULL;
	}
	return(insert);
}