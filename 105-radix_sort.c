#include "sort.h"
/**
 * radix_sort - Sort an array of integers in ascending order using the
 *              Radix sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max_value, exp, i;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max_value = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	for (exp = 1; max_value / exp > 0; exp *= 10)
	{
		int count[10] = {0};

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(output);
}
