#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 *in ascending order using the Bubble sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: number of integers in array
 */

void bubble_sort(int *array, size_t size)
{
size_t i;
int temp;
int swaps = -1;

if (size < 2)
return;

while (swaps)
{
swaps = 0;
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
swaps++;
print_array(array, size);
}
}
}
}
