#include "sort.h"
/**
 * quick_pivot - use quick sort and get idx_pivot
 * @array: The array
 * @size: The size of the array
 * @min: The minimum index of the array
 * @max: the maximum index of the array
 * Return: index position of pivot
 */
int quick_pivot(int *array, size_t size, int min, int max)
{
	int pivot = array[max];
	int runner = min;
	int chaser = min;
	int tmp = 0;

	while (runner < max)
	{
		if (array[runner] < pivot)
		{
			if (runner != chaser && array[runner] != array[chaser])
			{
				tmp = array[runner];
				array[runner] = array[chaser];
				array[chaser] = tmp;
				print_array(array, size);
			}
			chaser++;
		}
		runner++;
	}
	if (max != chaser && array[max] != array[chaser])
	{
		tmp = array[runner];
		array[runner] = array[chaser];
		array[chaser] = tmp;
		print_array(array, size);
	}
	return (chaser);
}
/**
 * partition - send chunks with idx pivot limit to sort.
 * @array: array.
 * @size: size of the array.
 * @min: The minimum index of the array.
 * @max: the maximum index of the array.
 */
void partition(int *array, size_t size, int min, int max)
{
	int idx_pivot;

	if (min < max)
	{
		idx_pivot = quick_pivot(array, size, min,  max);
		partition(array, size, min, idx_pivot - 1);
		partition(array, size, idx_pivot + 1, max);
	}
}
/**
 * quick_sort - Sort an array with quick sort method
 * @array: int array.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int max = size - 1;
	int min = 0;

	if (size < 2)
		return;
	partition(array, size, min, max);
}
