#include <stdlib.h>
#include <stdio.h>
#include "array.h"

// Initial array capacity
#define INITIAL_CAPACITY 2

Array *array_create(void)
{
  Array *array = (Array *)malloc(sizeof(Array));
  if (array == NULL)
  {
    fprintf(stderr, "array_create: unable to allocate memory for the ordered array");
    exit(EXIT_FAILURE);
  }
  array->array = (void **)malloc(INITIAL_CAPACITY * sizeof(void *));
  if (array->array == NULL)
  {
    fprintf(stderr, "array_create: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  array->el_num = 0;
  array->array_capacity = INITIAL_CAPACITY;

  return (array);
}

int array_is_empty(Array *array)
{
  if (array == NULL)
  {
    fprintf(stderr, "array_is_empty: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if (array->el_num == 0)
    return (1);
  return (0);
}

unsigned long array_size(Array *array)
{
  if (array == NULL)
  {
    fprintf(stderr, "array_size: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return (array->el_num);
}


void array_add(Array *array, void *element)
{
  if (array == NULL)
  {
    fprintf(stderr, "array_add: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }

  if (element == NULL)
  {
    fprintf(stderr, "array_add: element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }

  if (array->el_num >= array->array_capacity)
  {
    array->array = (void **)(realloc(array->array, 2 * array->array_capacity * sizeof(void *)));
    if (array->array == NULL)
    {
      fprintf(stderr, "array_add: unable to reallocate memory to host the new element");
      exit(EXIT_FAILURE);
    }
    array->array_capacity = 2 * array->array_capacity;
  }

  (array->array)[(array->el_num)] = element;
  (array->el_num)++;
}


void *array_get(Array *array, unsigned long i)
{
  if (array == NULL)
  {
    fprintf(stderr, "array_get: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if (i >= array->el_num)
  {
    fprintf(stderr, "array_get: Index %lu is out of the array bounds", i);
    exit(EXIT_FAILURE);
  }
  return (array->array)[i];
}

void array_free_memory(Array *array)
{
  if (array == NULL)
  {
    fprintf(stderr, "array_free_memory: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(array->array);
  free(array);
}
