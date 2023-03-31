#ifndef ARRAY_H_laokjsdnbudjllvfidkfmqm
#define ARRAY_H_laokjsdnbudjllvfidkfmqm

// It represents the internal structure of this implementation of arrays 

typedef struct _Array
{
  void **array;
  unsigned long el_num;
  unsigned long array_capacity;
} Array;

// It creates an empty array and returns the created array.
Array *array_create(void);

// It accepts as input a pointer to an array and it returns 1 iff
// the array is empty, 0 otherwise.
// The input parameter cannot be NULL.
int array_is_empty(Array *array);

// It accepts as input a pointer to an array and it
// returns the number of elements currently stored into the array.
// The input parameter cannot be NULL.
unsigned long array_size(Array *array);

// It accepts as input a pointer to an array and a pointer to an element. It adds
// the element to the array in the right position.
// The input parameters cannot be NULL.
void array_add(Array *array, void *element);

// It accepts as input a pointer to an array and an integer "i" and
// it returns the pointer to the i-th element of the array
// The first parameter cannot be NULL; the second parameter must be a valid position
// into the array.
void *array_get(Array *array, unsigned long i);

// It accepts as input a pointer to an array and
// it deallocates the memory allocated to store the array.
// It does not free the memory allocated to store the array elements
// The input parameters cannot be NULL.
void array_free_memory(Array *array);

#endif /* ARRAY_H_laokjsdnbudjllvfidkfmqm */
