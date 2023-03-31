#include <stdio.h>
#include <stdlib.h>
#include "sorting_library.h"

// it accepts a pointer to the array of records and two indexes that represent the positions of the elements
// to be swapped
// it swaps the element at position i with the element at position j
// array is not NULL and i and j must be included between 0 and array -> el_num
void swap(Array *array, unsigned long i, unsigned long j)
{
  if(i<array->el_num && j<array->el_num){
    void *temp = (array->array)[i];
    (array->array)[i] = (array->array)[j];
    (array->array)[j] = temp;
  }
}

// it accepts a pointer to the array of records, a pointer to the comparison criteria and
// two indexes that represent the partition of the array to be ordered
// it partitions the elements according to the pivot element
// pointers are not NULL
unsigned long partition(Array *array, int (*precedes)(void *, void *), unsigned long i, unsigned long j)
{
  // Pre-condition: array not null,not empty and i < j
  // Post-condition: (i <= pivot: A[i] <= A[pivot]) and (j > pivot: A[j] > A[pivot])
  unsigned long p_index = (i + j)/2;
  void *pivot = array_get(array, p_index);

  while (i < j)
  {
    //i<=pivot
    while (i < j && (precedes(array_get(array, i), pivot) == 1 || precedes(array_get(array, i), pivot) == 0))
    {
      i++;
    }
    //j>pivot
    while (precedes(array_get(array, j), pivot) == -1)
    {
      j--;
    }
    //si è fermato a un minorante j e i a un minorante
    //perciò li swappo e riciclo col while
    if (i < j)
    {
      swap(array, i, j);
    }
  }

  if (i == j && i != p_index)
  {
    swap(array, i, p_index);
  }

  return i;
}


// it accepts a pointer to the array of records, a pointer to the comparison criteria and
// two indexes that represent the partition of the array to be ordered
// it sorts the elements of the array between i and j
// pointers are not NULL, i and j must be included between 0 and array -> el_num
void quick_sort_ric(Array *array, int (*precedes)(void *, void *), unsigned long i, unsigned long j)
{
  if (i >= j)
  {
    return;
  }
  else
  {
    unsigned long pivot = partition(array, precedes, i, j);
    quick_sort_ric(array, precedes, i, pivot - 1);
    quick_sort_ric(array, precedes, pivot, j);
  }
}

// it accepts a pointer to the array of records, a pointer to the comparison criteria
// it is a wrapper of the quicksort algorithm to be used
void quick_sort(Array *array, int (*precedes)(void *, void *))
{

  quick_sort_ric(array, precedes, 0, (unsigned long)(array->el_num) - 1);
}

// it accepts a pointer to the array of records, a pointer to the comparison criteria,
// a pointer to the element to be placed in the right position and the right extreme of the range
// it returns the position where will be inserted curr_el
// pointers are not NULL, k must be included between 1 and array -> el_num
unsigned long binary_search(Array *array, int (*precedes)(void *, void *), void *curr_el, unsigned long k)
{
  unsigned long left, right, pos;
  left = 0;
  right = k;
  while (left < right)
  {
    pos = (left + right) / 2;
    //pos<=curr_el
    if (precedes(array_get(array, (unsigned long)pos), curr_el) >= 0)
      //se <=vado a destra spostando left a pos+1
      left = pos + 1;
    else
      //se > scendo a sinistra metto right a pos
      right = pos;
  }
  return left;
}

// it accepts a pointer to the array of records and a pointer to the comparison criteria
// it sorts the elements of the array based on insertion sort algorithm logic
// using binary search method to find the right position of the current element
// pointers are not NULL
void insertion_sort(Array *array, int (*precedes)(void *, void *))
{
  if (array->el_num > 1)
  {
    unsigned long i, j, pos;
    for (i = 1; i < (array->el_num); i++)
    {
      void *curr_el = array->array[i];
      pos = binary_search(array, precedes, curr_el, i);
      j = i;
      while (j > pos)
      {
        array->array[j] = array->array[j - 1];
        j--;
      }
      array->array[pos] = curr_el;
    }
  }
}

