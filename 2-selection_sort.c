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
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m_idx;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		m_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_idx])
				m_idx = j;
		}
		if (m_idx != i)
		{
			swap(&array[i], &array[m_idx]);
			print_array(array, size);
		}
	}
}
