#include "sort.h"

/**
 * bubble_sort - Sort an array using bubble sort
 * @array: list of integer to sort
 * @size: list size
 */
void bubble_sort(int *array, size_t size)
{
	int keeper;
	size_t index = 0;
	size_t arr_size = size;

	while (size > 0)
	{
		if (array && index < size)
		{
			if (array[index] > array[index + 1])
			{
				keeper = array[index];
				array[index] = array[index + 1];
				array[index + 1] = keeper;
				index++;
				print_array(array, arr_size);
			}
			else
			{
				index++;
			}
		}
		else
		{
			size--;
			index = 0;
		}
	}
}
