#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int precedes3cases_record_field1(void *first_record, void *second_record) // 3 casi distinti
{
  int check_int, check_string;
  float check_float;
  if (first_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field1: the first parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  if (second_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field1: the second parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  record *first_rec = (record *)first_record;
  record *second_rec = (record *)second_record;
  if ((check_string = strcmp(first_rec->string_field1, second_rec->string_field1)) < 0)
  {
    return (1);
  }
  else if (check_string == 0)
  {
    return 0;
    check_int = first_rec->integer_field2 - second_rec->integer_field2;
    if (check_int < 0)
    {
      return (1);
    }
    else if (check_int == 0)
    {
      check_float = first_rec->float_field3 - second_rec->float_field3;
      if (check_float < 0)
      {
        return (1);
      }
      else if (check_float > 0)
      {
        return -1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return (-1);
    }
  }
  else
  {
    return (-1);
  }
}
int precedes3cases_record_field2(void *first_record, void *second_record) // 3 casi
{
  int check_int, check_string;
  float check_float;
  if (first_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field2: the first parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  if (second_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field2: the second parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  record *first_rec = (record *)first_record;
  record *second_rec = (record *)second_record;
  // se A-B<0 --> A<B
  if ((check_int = first_rec->integer_field2 - second_rec->integer_field2) < 0)
  {
    return (1);
  }
  else if (check_int == 0)
  {
    check_float = first_rec->float_field3 - second_rec->float_field3;
    if (check_float < 0)
    {
      return (1);
    }
    else if (check_float == 0)
    {
      check_string = strcmp(first_rec->string_field1, second_rec->string_field1);
      if (check_string < 0)
      {
        return (1);
      }
      else if (check_string > 0)
      {
        return -1;
      }
      return (0);
    }
    return (-1);
  }
  else
  {
    return (-1);
  }
}

int precedes3cases_record_field3(void *first_record, void *second_record) // 3 casi
{
  int check_int, check_string;
  float check_float;
  if (first_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field3: the first parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  if (second_record == NULL)
  {
    fprintf(stderr, "%s: %d. Precedes_record_field3: the second parameter is a null pointer", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  record *first_rec = (record *)first_record;
  record *second_rec = (record *)second_record;
  if ((check_float = first_rec->float_field3 - second_rec->float_field3) < (float)0)
  {
    return (1);
  }
  else if (check_float == (float)0)
  {
    check_string = strcmp(first_rec->string_field1, second_rec->string_field1);
    if (check_string < 0)
    {
      return (1);
    }
    else if (check_string == 0)
    {
      check_int = first_rec->integer_field2 - second_rec->integer_field2;
      if (check_int < 0)
      {
        return (1);
      }
      if (check_int == 0)
      {
        return 0;
      }
      return (-1);
    }
    return (-1);
  }
  else
  {
    return (-1);
  }
}
