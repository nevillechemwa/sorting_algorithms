#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge two subarrays of array[]
 * @array: Pointer to array to be sorted
 * @low: Starting index of the first subarray
 * @count: Number of elements to be sorted
 * @dir: Order (UP/DOWN) of sorting
 */
void bitonic_merge(int *array, int low, size_t count, int dir)
{
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++) {
            if ((array[i] > array[i + k]) == dir) {
                int tmp = array[i];
                array[i] = array[i + k];
                array[i + k] = tmp;
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * @array: Pointer to array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    for (int k = 2; k <= size; k *= 2) {
        for (int j = k / 2; j > 0; j /= 2) {
            for (int i = 0; i < size; i += k) {
                bitonic_merge(array, i, j, UP);
                bitonic_merge(array, i + j, j, DOWN);
            }
        }
        if (k != size) {
            printf("Merging [%lu/%lu] (UP):\n", size, size);
            print_array(array, size);
        }
    }
}

