#include "sort.h"
/**
 * extract_node - extract the next node
 * @list: head of the list
 */

listint_t *extract_node(listint_t **runner)
{
    listint_t *insert = *runner;

	if (insert->next)
	{
		insert->prev->next = insert->next;
		insert->next->prev = insert->prev;
	}
	else
	{
		insert->prev->next = NULL;
	}
	return(insert);
}
