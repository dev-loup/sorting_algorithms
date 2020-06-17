#include "sort.h"
/**
 * insertion_sort_list - Sort a dlinked list using bubble sort
 * @list: head of the list
 */

void selection_sort(int *array, size_t size)
{
	size_t index = 0;
	size_t index2;
	size_t min;
	int temp;

	while (index < size)
	{
		min = index;
		index2 = index;
		while (index2 < size)
		{
			if (array[index2] < array[min])
				min = index2;
			index2++;
		}
		if (min != index)
		{
			temp = array[index];
			array[index] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		index++;
	}
}
