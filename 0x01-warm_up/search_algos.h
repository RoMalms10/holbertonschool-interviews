#ifndef SEARCH_ALGO
#define SEARCH_ALGO

#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, size_t size, int value);
int helper(int *array, int value, int lo, int hi);
void print_array(int *array, int lo, int hi);

#endif
