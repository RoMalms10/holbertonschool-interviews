#include "search_algos.h"

void print_array(int *array, int lo, int hi)
{
	int i = 0;

	printf("Searching in array: ");
	for (i = lo; i <= hi; i++)
	{
		if (i != lo)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

int helper(int *array, int value, int lo, int hi)
{
	int mid = 0;

	print_array(array, lo, hi);
	mid = lo + ((hi - lo) / 2);
	if (array[mid] == value)
		return (mid);
	if (hi == lo || lo > hi)
		return (-1);
	if (array[mid] > value)
		return (helper(array, value, lo, mid - 1));
	else if (array[mid] < value)
		return (helper(array, value, mid + 1, hi));
	return (-1);
}

int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (helper(array, value, 0, size - 1));
}
