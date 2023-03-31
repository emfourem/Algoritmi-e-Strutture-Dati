#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "skiplist.h"

// This method implements a lexicographic compare between two strings ignoring case
// It accepts two void pointers that cannot be null
// The method returns 0 if strings are the same, less than 0 if item1 precedes item2 and greater than 0 otherwise
int compare_string(void *item1, void *item2)
{
  if (item2 == NULL)
  {
    fprintf(stderr, "compare_string : item parameter to insert/search cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  int i = strcasecmp((char *)item1, (char *)item2);
  return i;
}

// This method loads skip list in main memory, parsing it from a file represented by given filename
// It accepts two parameters: a string representing filename, and a pointer to the data structure that will contain parsed information
// At the end of the method skiplist will contain all the word parsed from the file
void load_skiplist(char const *filename, SkipList *list)
{
  char *read_line_p;
  char buffer[1024];
  int buf_size = 1024, cont = 0;
  time_t t, t_tot = 0;
  FILE *fp;
  printf("Loading data from file...\n");
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "laod_skiplist: unable to open the file");
    exit(EXIT_FAILURE);
  }
  while (fgets(buffer, buf_size, fp) != NULL)
  {
    read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
    if (read_line_p == NULL)
    {
      fprintf(stderr, "load_skiplist: unable to allocate memory for the read line");
      exit(EXIT_FAILURE);
    }
    strcpy(read_line_p, buffer);

    char *word = strtok(read_line_p, "\n");

    char *string = malloc((strlen(word) + 1) * sizeof(char));
    if (string == NULL)
    {
      fprintf(stderr, "load_skiplist: unable to allocate memory for the string field of the read word\n");
      exit(EXIT_FAILURE);
    }
    strcpy(string, word);
    t = clock();
    insert_skiplist(list, (void *)string);
    t = clock() - t;
    t_tot += t;
    cont++;
    free(read_line_p);
  }
  printf("Il tempo medio dell'inserimento è %.7f \n", ((float)t_tot / CLOCKS_PER_SEC) / (float)cont);
  fclose(fp);
}

// This method prints onto stdout the data stored in the list
// It accepts a pointer (that cannot be NULL) to the structure that contains words

void print_list(SkipList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "print_list : list parameter cannot be NULL.\n");
    exit(EXIT_FAILURE);
  }
  int k = 0;
  Node *n = list->head->next[k];
  printf("\nSkiplist: \n");
  for (; n != NULL; n = n->next[k])
  {
    printf("%s \n", (char *)n->item);
  }
}

// This method is used to check the grammar of a given text file
// It accepts two parameters: a pointers that holds the dictionary as a skiplist data structure
//and a pointer to the file, represented by its filename path
void read_text(SkipList *skiplist, char const *filename)
{
  time_t t;
  time_t t_tot = 0;
  int cont = 0;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "read_text : unable to open the file");
  }
  int n = 0;
  char ch;
  char *string = NULL;
  printf("Massima altezza skiplist: %d\n", MAX_HEIGHT);
  while ((ch = (char)fgetc(fp)) != EOF)
  {
    if (isalpha(ch) > 0)
    {
      string = (char *)realloc(string, (size_t)n + 1);
      string[n++] = ch;
      while ((ch = (char)fgetc(fp)) != EOF && isalpha(ch) > 0) // finchè trovo lettere
      {
        string = (char *)realloc(string, (size_t)n + 1);
        string[n++] = ch;
      }
      string[n] = '\0';
      t = clock();
      search_skiplist(skiplist, (void *)string);
      t = clock() - t;
      cont++;
      t_tot += t;
      string = NULL;
    }
    n = 0;
  }
  printf("Tempo medio ricerca: %.7f secondi\n", ((float)t_tot / CLOCKS_PER_SEC) / (float)cont);
  free(string);
  free_memory_skiplist(skiplist);
}

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Error: use ./main_ex2 path_dictionary path_correctme");
    exit(EXIT_FAILURE);
  }
  srand((unsigned int)time(NULL));
  SkipList *skiplist = create_skiplist(compare_string);
  load_skiplist(argv[1], skiplist);
  read_text(skiplist, argv[2]);
  return 0;
}
