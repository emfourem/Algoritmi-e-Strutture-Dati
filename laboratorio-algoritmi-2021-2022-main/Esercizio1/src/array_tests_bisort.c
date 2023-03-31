#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "test.h"
#include "sorting_library.h"



// Data elements that are initialized before each test
static record i1, i2, i3;
static Array *_array;

void setUp(void)
{
  i1.id = 0;
  i1.string_field1 = "First";
  i1.integer_field2 = 42341;
  i1.float_field3 = (float)42341.567;
  i2.id = 0;
  i2.string_field1 = "Second";
  i2.integer_field2 = 42341;
  i2.float_field3 = (float)34526.987;
  i3.id = 0;
  i3.string_field1 = "Third";
  i3.integer_field2 = 263318;
  i3.float_field3 = (float)42341.123;
  _array = array_create();
}

void tearDown(void)
{ 
  array_free_memory(_array);
}

static void test__array_zero_elem(void)
{
  TEST_ASSERT_TRUE(array_is_empty(_array));
}

static void test__array_one_el(void)
{
  array_add(_array, &i1);
  TEST_ASSERT_FALSE(array_is_empty(_array));
}

static void test__array_size(void)
{
  TEST_ASSERT_EQUAL_INT(0, array_size(_array));
}

static void test__one_elem_string(void)
{
  record *exp_arr[] = {&i1};
  array_add(_array, &i1);
  insertion_sort(_array, precedes3cases_record_field1);
  record **act_arr = malloc(1 * sizeof(record *));
  for (unsigned long i = 0; i < 1; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 1);
}
static void test__one_elem_int(void)
{
  record *exp_arr[] = {&i2};
  array_add(_array, &i2);
  insertion_sort(_array, precedes3cases_record_field2);
  record **act_arr = malloc(1 * sizeof(record *));
  for (unsigned long i = 0; i < 1; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 1);
}
static void test__one_elem_float(void)
{
  record *exp_arr[] = {&i1};
  array_add(_array, &i1);
  insertion_sort(_array, precedes3cases_record_field3);
  record **act_arr = malloc(1 * sizeof(record *));
  for (unsigned long i = 0; i < 1; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 1);
}

static void test__three_elem_string(void)
{
  record *exp_arr[] = {&i1, &i2, &i3};
  array_add(_array, &i3);
  array_add(_array, &i1);
  array_add(_array, &i2);
  insertion_sort(_array, precedes3cases_record_field1);
  record **act_arr = malloc(3 * sizeof(record *));
  for (unsigned long i = 0; i < 3; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}
static void test__three_elem_int(void)
{
  record *exp_arr[] = {&i2, &i1, &i3};
  array_add(_array, &i3);
  array_add(_array, &i2);
  array_add(_array, &i1);
  insertion_sort(_array, precedes3cases_record_field2);
  record **act_arr = malloc(3 * sizeof(record *));
  for (unsigned long i = 0; i < 3; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}
static void test__three_elem_float(void)
{
  record *exp_arr[] = {&i2, &i3, &i1};
  array_add(_array, &i3);
  array_add(_array, &i1);
  array_add(_array, &i2);
  insertion_sort(_array, precedes3cases_record_field3);
  record **act_arr = malloc(3 * sizeof(record *));
  for (unsigned long i = 0; i < 3; i++)
    act_arr[i] = (record *)array_get(_array, i);
  TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test__array_zero_elem);
  RUN_TEST(test__array_one_el);
  RUN_TEST(test__array_size);
  RUN_TEST(test__one_elem_string);
  RUN_TEST(test__one_elem_int);
  RUN_TEST(test__one_elem_float);
  RUN_TEST(test__three_elem_string);
  RUN_TEST(test__three_elem_int);
  RUN_TEST(test__three_elem_float);

  return UNITY_END();
}

