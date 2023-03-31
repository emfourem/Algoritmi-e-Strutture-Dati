#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting_library.h"

// it represents the structure of the records to be ordered
//struct record per leggere il file in input che è così composto <id,string,int,float>
struct record
{
  int id;
  char *string_field1;
  int integer_field2;
  float float_field3;
};

// it accepts two pointers of the records to compare
// comparison order:
// (1) string_field
// (2) integer_field
// (3) floating_point
// it returns:
// -1 if first_record > second_record
// 0 if first_record == second_record
// 1 if first_record < second_record
// parameters cannot be NULL
static int precedes3cases_record_field1(void *first_record, void *second_record) // 3 casi distinti
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
  struct record *first_rec = (struct record *)first_record;
  struct record *second_rec = (struct record *)second_record;
  //<0 allora s1<s2
  if ((check_string = strcasecmp(first_rec->string_field1, second_rec->string_field1)) < 0)
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

// it accepts two pointers of the records to compare
// comparison order:
// (1) integer_field
// (2) floating_point_field
// (3) string_field
// it returns:
// -1 if first_record > second_record
// 0 if first_record == second_record
// 1 if first_record < second_record
// parameters cannot be NULL
static int precedes3cases_record_field2(void *first_record, void *second_record) // 3 casi
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
  struct record *first_rec = (struct record *)first_record;
  struct record *second_rec = (struct record *)second_record;
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
      check_string = strcasecmp(first_rec->string_field1, second_rec->string_field1);
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

// it accepts two pointers of the records to compare
// comparison order:
// (1) floating_point_field
// (2) string_field
// (3) integer_field
// it returns:
// -1 if first_record > second_record
// 0 if first_record == second_record
// 1 if first_record < second_record
// parameters cannot be NULL
static int precedes3cases_record_field3(void *first_record, void *second_record) // 3 casi
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
  struct record *first_rec = (struct record *)first_record;
  struct record *second_rec = (struct record *)second_record;
  if ((check_float = first_rec->float_field3 - second_rec->float_field3) < (float)0)
  {
    return (1);
  }
  else if (check_float == (float)0)
  {
    check_string = strcasecmp(first_rec->string_field1, second_rec->string_field1);
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

// it accepts a pointer to an array to be deallocated
// it deallocates the array
// parameter cannot be NULL
static void free_array(Array *array)
{
  if(array==NULL){
    fprintf(stderr, "free_array:pointer to array to deallocate cannot be null");
    exit(EXIT_FAILURE);
  }
  //free sul campo string perchè deriva da una malloc
  //free della struct intera
  //free dell'array finale
  unsigned long el_num = array_size(array);
  for (unsigned long i = 0; i < el_num; i++)
  {
    struct record *array_element = (struct record *)array_get(array, i);
    free(array_element->string_field1);
    free(array_element);
  }
  array_free_memory(array);
}

/*
// it accepts a pointer to the string representing the path
// to the file that contains the records to be sorted,
// a pointer to the array that will contain the records
// and an integer that represents the number of elements to be sorted
// parameters cannot be NULL
static void load_array_with_limit(const char *file_name, Array *array, int limit)
{
  if(array==NULL){
    fprintf(stderr, "load_array_with_limit:pointer to array to load cannot be null");
    exit(EXIT_FAILURE);
  }
  char *read_line_p;
  char buffer[1024];
  int buf_size = 1024;
  FILE *fp;
  printf("Loading data from file...\n");
  fp = fopen(file_name, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "load_array_with_limit: unable to open the file");
    exit(EXIT_FAILURE);
  }
  while (fgets(buffer, buf_size, fp) != NULL && limit--)
  {
    read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
    if (read_line_p == NULL)
    {
      fprintf(stderr, "load_array_with_limit: unable to allocate memory for the read line");
      exit(EXIT_FAILURE);
    }
    strcpy(read_line_p, buffer);

    char *id_in_read_line_p = strtok(read_line_p, ",");
    char *string_field1_in_read_line_p = strtok(NULL, ",");
    char *integer_field2_in_read_line_p = strtok(NULL, ",");
    char *float_field3_in_read_line_p = strtok(NULL, ",\n");

    char *string_field1 = malloc((strlen(string_field1_in_read_line_p) + 1) * sizeof(char));
    if (string_field1 == NULL)
    {
      fprintf(stderr, "load_array_with_limit: unable to allocate memory for the string field of the read record");
      exit(EXIT_FAILURE);
    }
    strcpy(string_field1, string_field1_in_read_line_p);

    int integer_field2 = atoi(integer_field2_in_read_line_p);
    int id = atoi(id_in_read_line_p);
    float float_field3 = (float)(atof(float_field3_in_read_line_p));

    struct record *record_p = malloc(sizeof(struct record));
    if (record_p == NULL)
    {
      fprintf(stderr, "load_array_with_limit: unable to allocate memory for the read record");
      exit(EXIT_FAILURE);
    }
    record_p->id = id;
    record_p->string_field1 = string_field1;
    record_p->integer_field2 = integer_field2;
    record_p->float_field3 = float_field3;

    array_add(array, (void *)record_p);
    free(read_line_p);
  }
  fclose(fp);
  printf("Data loaded\n\n");
}
*/



// it accepts a pointer to the string representing the path
// to the file that contains the records to be sorted,
// a pointer to the array that will contain the records
// parameters cannot be NULL
static void load_array(const char *file_name, Array *array)
{
  if(array==NULL){
    fprintf(stderr, "load_array:pointer to array to load cannot be null");
    exit(EXIT_FAILURE);
  }
  char *read_line_p;
  char buffer[1024];
  int buf_size = 1024;
  FILE *fp;
  printf("Loading data from file...\n");
  fp = fopen(file_name, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "load_array: unable to open the file");
    exit(EXIT_FAILURE);
  }
  //fgets legge buf_size caratteri da fp fino all'EOF e li mette in buffer
  while (fgets(buffer, buf_size, fp) != NULL)
  {
    read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
    if (read_line_p == NULL)
    {
      fprintf(stderr, "load_array: unable to allocate memory for the read line");
      exit(EXIT_FAILURE);
    }
    strcpy(read_line_p, buffer);

    char *id_in_read_line_p = strtok(read_line_p, ",");
    char *string_field1_in_read_line_p = strtok(NULL, ",");
    char *integer_field2_in_read_line_p = strtok(NULL, ",");
    char *float_field3_in_read_line_p = strtok(NULL, ",\n");

    char *string_field1 = malloc((strlen(string_field1_in_read_line_p) + 1) * sizeof(char));
    if (string_field1 == NULL)
    {
      fprintf(stderr, "load_array: unable to allocate memory for the string field of the read record");
      exit(EXIT_FAILURE);
    }
    strcpy(string_field1, string_field1_in_read_line_p);

    int integer_field2 = atoi(integer_field2_in_read_line_p);
    int id = atoi(id_in_read_line_p);
    float float_field3 = (float)(atof(float_field3_in_read_line_p));

    struct record *record_p = malloc(sizeof(struct record));
    if (record_p == NULL)
    {
      fprintf(stderr, "load_array: unable to allocate memory for the read record");
      exit(EXIT_FAILURE);
    }
    record_p->id = id;
    record_p->string_field1 = string_field1;
    record_p->integer_field2 = integer_field2;
    record_p->float_field3 = float_field3;
    //aggiunge in ultima posizione il record appena letto
    array_add(array, (void *)record_p);
    free(read_line_p);
  }
  fclose(fp);
  printf("Data loaded\n\n");
}

// it accepts a pointer that represents the path to the output file,
// a pointer to the array that contains the records to be written to file
void write_array(const char *filename, Array *array)
{
  if (array == NULL)
  {
    printf("write_array:array to write cannot be null");
    exit(EXIT_FAILURE);
  }

  long unsigned int el_num = array_size(array);
  struct record *record;
  char buffer[128];
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL)
  {
    fprintf(stderr, "write_array: unable to open the file %s",filename);
    exit(EXIT_FAILURE);
  }
  for (long unsigned int i = 0; i < el_num; i++)
  {
    record = (struct record *)array_get(array, i);
    //copio in buffer con snprintf 128 byte,contenenti i campi del record
    snprintf(buffer, 128, "[%d,%s,%d,%f]\n", record->id, record->string_field1, record->integer_field2, record->float_field3); // not portable -use-> sprintf(...)
    //fputs mette il contenuto del buffer in fp senza carattere terminatorio
    fputs(buffer, fp);
    //'azzera' il contenuto del buffer per 128 bytes,ovvero per tutta la lunghezza..per la successiva iterazione
    bzero(buffer, 128);
  }
  printf("Data has been written to path %s\n", filename);
  fclose(fp);
}




int main(int argc, char const *argv[])
{
  if (argc < 5)
  {
    printf("Usage: sorting_main <file_name_IN> <file_name_OUT> <algorithm> <field>\n");
    exit(EXIT_FAILURE);
  }
  clock_t t;
  Array *array = array_create();
  load_array(argv[1], array);
  //load_array_with_limit(argv[1], array,1000);
  // time_before_sorting
  if (strcmp(argv[3], "quicksort") == 0)
  {
    printf("Algorithm : quicksort\n");
    switch(atoi(argv[4])){
      case 1:
        t = clock();
        quick_sort(array,precedes3cases_record_field1);
        break;
      case 2:
        t = clock();
        quick_sort(array,precedes3cases_record_field2);
        break;
      case 3:
        t = clock();
        quick_sort(array,precedes3cases_record_field3);
        break;
      default:
        printf("Usage : enter 1 for string field, 2 for int field, 3 for float field\n");
        exit(EXIT_FAILURE);
    }
  }
  else if (strcmp(argv[3], "bis") == 0)
  {
    printf("Algorithm : binary insertion sort\n");
    switch(atoi(argv[4])){
      case 1:
        t = clock();
        insertion_sort(array,precedes3cases_record_field1);
        break;
      case 2:
        t = clock();
        insertion_sort(array,precedes3cases_record_field2);
        break;
      case 3:
        t = clock();
        insertion_sort(array,precedes3cases_record_field3);
        break;
      default:
        printf("Usage : enter 1 for string field, 2 for int field, 3 for float field\n");
        exit(EXIT_FAILURE);
    }
  }
  else
  {
    printf("Usage : write 'quicksort' for quicksort or 'bis' for binary insertion sort\n");
    exit(EXIT_FAILURE);
  }
  t = clock() - t;
  // time_after_sorting
  write_array(argv[2], array);
  printf("The algorithm took %f seconds to sort the records\n", ((float)t) / CLOCKS_PER_SEC);
  free_array(array);
  return (EXIT_SUCCESS);
}
