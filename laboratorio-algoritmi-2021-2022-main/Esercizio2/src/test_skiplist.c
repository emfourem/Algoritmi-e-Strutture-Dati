#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "skiplist.h"

int compare_string(void *item1, void *item2)
{
  if (item1 == NULL || item2 == NULL)
  {
    fprintf(stderr, "compare_string : item parameter to insert/search cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  int i = strcasecmp((char *)item1, (char *)item2);
  return i;
}

static SkipList *skiplist;

void setUp(void)
{
  skiplist = create_skiplist(compare_string);
}

void tearDown(void)
{
  free_memory_skiplist(skiplist);
}

static void test_skiplist_is_empty(void)
{
  TEST_ASSERT_TRUE(skiplist_is_empty(skiplist));
}

static void test_skiplist_is_not_empty(void)
{
  char *string1 = (char *)malloc(sizeof(char) * (2));
  string1[0] = 'a';
  string1[1] = '\0';
  insert_skiplist(skiplist, (void *)string1);
  TEST_ASSERT_FALSE(skiplist_is_empty(skiplist));
}

static void test__array_size(void)
{
  TEST_ASSERT_EQUAL_INT(0, skiplist_size(skiplist));
}

static void test_one_elem_string(void)
{
  char *string1 = (char *)malloc((strlen("Montesi") + 1) * sizeof(char));
  strcpy(string1, "Montesi");
  insert_skiplist(skiplist, string1);
  TEST_ASSERT_EQUAL_INT(0, skiplist->compare(string1, search_skiplist(skiplist, string1)));
}
static void test_two_elem_string(void)
{
  char *string1 = (char *)malloc((strlen("Montesi") + 1) * sizeof(char));
  strcpy(string1, "Montesi");
  char *string2 = (char *)malloc((strlen("Merico") + 1) * sizeof(char));
  strcpy(string2, "Merico");
  insert_skiplist(skiplist, string1);
  insert_skiplist(skiplist, string2);
  TEST_ASSERT_EQUAL_INT(0, skiplist->compare(string2, search_skiplist(skiplist, string2)));
}
static void test_three_elem_string(void)
{
  char *string1 = (char *)malloc((strlen("Montesi") + 1) * sizeof(char));
  strcpy(string1, "Montesi");
  char *string2 = (char *)malloc((strlen("Merico") + 1) * sizeof(char));
  strcpy(string2, "Merico");
  char *string3 = (char *)malloc((strlen("Turcan") + 1) * sizeof(char));
  strcpy(string3, "Turcan");
  insert_skiplist(skiplist, string1);
  insert_skiplist(skiplist, string2);
  insert_skiplist(skiplist, string3);
  TEST_ASSERT_EQUAL_INT(0, skiplist->compare(string3, search_skiplist(skiplist, string3)));
}

int main(void)
{
  // test session
  UNITY_BEGIN();

  RUN_TEST(test_skiplist_is_empty);
  RUN_TEST(test_skiplist_is_not_empty);
  RUN_TEST(test__array_size);
  RUN_TEST(test_one_elem_string);
  RUN_TEST(test_two_elem_string);
  RUN_TEST(test_three_elem_string);

  return UNITY_END();
}
