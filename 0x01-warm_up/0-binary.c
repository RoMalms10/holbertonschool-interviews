#include "search_algos.h"

/**
  * print_array - prints the array every time
  * @array: the array to print
  * @lo: the lowest point in the array
  * @hi: the highest point in the array
  * Return: Nothing, void
  */
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

/**
  * helper - recurses through the array until the value is found
  * @array: the array to look through
  * @value: the value to look for
  * @lo: the lowest point in the array
  * @hi: the highest point in the aray
  * Return: The index of where the value was found
  */
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

/**
  * binary_search - passes off the information to a recursive function
  * @array: the array to look through
  * @size: size of the array
  * @value: the value to look for
  * Return: The index of where the value was found
  */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (helper(array, value, 0, size - 1));
}
