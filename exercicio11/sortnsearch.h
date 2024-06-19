#ifndef _sortnsearch_h_
#define _sortnsearch_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void bubble_sort(int * array, int size);

void quick_sort(int * array, int size);

int linear_search(int * array, int size, int wanted);

int binary_search(int * array, int beg, int size, int wanted);

void print_array(int * array, int size);

#endif