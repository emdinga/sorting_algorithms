#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t g = 1
		size_t i, b;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;
	while (gap >= 1)
	{
		for (i = g; i < size; i++)
		{
			temp = array[i];
			b = i;
			while (b >= g && array[b - g] > temp)
			{
				array[b] = array[b - g];
				b -= g;
			}
			array[b] = temp;
		}
		print_array(array, size);
		g /= 3;
	}
}
