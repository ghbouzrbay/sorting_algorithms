#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
  int hub, over;
  int below;

  hub = array[right];
  for (over = left - 1, below = right + 1; over < below;)
    {
      do {
	over++;
      } while (array[over] < hub);
      do {
	below--;
      } while (array[below] > hub);

      if (over < below)
	{
	  swap_ints(array + over, array + below);
	  print_array(array, size);
	}
    }

  return (over);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
  int bit;

  if (right - left > 0)
    {
      bit = hoare_partition(array, size, left, right);
      hoare_sort(array, size, left, bit - 1);
      hoare_sort(array, size, bit, right);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
  if (array == NULL || size < 2)
    return;

  hoare_sort(array, size, 0, size - 1);
}
