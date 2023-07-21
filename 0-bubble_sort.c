#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, c;
	int swapped;

	if (array == NULL ||  size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (c = 0; c < size - 1; c++)
		{
			if (array[c] > array[c + 1])
			{
				swap(&array[c], &array[c + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
