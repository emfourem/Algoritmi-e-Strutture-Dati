#ifndef SORTING_LIBRARY_ascjhasbwbhvhcys
#define SORTING_LIBRARY_ascjhasbwbhvhcys
#include "array.h"


// It accepts as input a pointer to an array to be sorted
// and a pointer to the function that represents comparison criteria
// The input parameters cannot be NULL
// It sorts the array in input using quicksort algorithm logic
void quick_sort(Array *, int (*precedes)(void *, void *));


// It accepts as input a pointer to an array to be sorted
// and a pointer to the function that represents comparison criteria
// The input parameters cannot be NULL
// It sorts the array in input using insertion sort algorithm logic with binary search to retreive
// the position of the elements to sort
void insertion_sort(Array *, int (*precedes)(void *, void *));


#endif
