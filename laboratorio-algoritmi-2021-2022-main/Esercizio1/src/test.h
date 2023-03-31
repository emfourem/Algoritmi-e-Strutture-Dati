#ifndef TEST_H_1
#define TEST_H_1


typedef struct _record
{
  int id;
  char *string_field1;
  int integer_field2;
  float float_field3;

}record;

int precedes3cases_record_field1(void *first_record, void *second_record);

int precedes3cases_record_field2(void *first_record, void *second_record);

int precedes3cases_record_field3(void *first_record, void *second_record);

#endif