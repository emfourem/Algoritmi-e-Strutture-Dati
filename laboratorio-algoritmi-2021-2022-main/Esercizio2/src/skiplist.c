#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "skiplist.h"

void *search_skiplist(SkipList *list, void *item)
{
  if (skiplist_is_empty(list) == 1)
  {
    printf("Item %s not found because skiplist is empty. \n", (char *)item);
    return item;
  }
  Node *first;
  first = (Node *)malloc(sizeof(Node));
  first = list->head;
  for (int i = list->max_level - 1; i >= 0; i--)
  {
    //s1<s2 se <0
    while (first->next != NULL && first->next[i] != NULL && list->compare(first->next[i]->item, item) < 0)
    {
      first = first->next[i];
    }
  }

  first = first->next[0];
  if (first != NULL && list->compare(first->item, item) == 0)
  {
    return first->item;
  }
  else
  {
    printf("%s\n", (char *)item);
    return item;
  }
}

// This is a private method to the API
// It returns the number tha will represent the length of array of nodes that a node can reffer to
int _random_level(void)
{
  int lvl = 1;

  while ((double)rand() / ((double)RAND_MAX + 1) < 0.5 && lvl < MAX_HEIGHT)
  {
    lvl++;
  }

  return lvl;
}

// This method is private to the API
// It helps to create a node that will be inserted into a skiplist
// It accepts a pointer to the item to be inserted
// The method returns a pointer to the created Node
Node *create_node_skiplist(void *item)
{
  Node *new_node;
  new_node = (Node *)malloc(sizeof(Node));
  new_node->item = item;
  new_node->size = _random_level();
  new_node->next = (Node **)calloc((size_t)new_node->size, sizeof(Node *));
  //creo i livelli e li setto tutti a NULL
  for (int i = 0; i < new_node->size; i++)
  {
    new_node->next[i] = NULL;
  }

  return new_node;
}

void insert_skiplist(SkipList *list, void *item)
{
  if (list == NULL)
  {
    fprintf(stderr, "insert_skiplist: list parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  if (item == NULL)
  {
    fprintf(stderr, "insert_skiplist: item parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  Node *new_node;
  new_node = create_node_skiplist(item);
  //se trovo il massimo,lo aggiorno nella skiplist
  if (new_node->size > list->max_level)
  {
    list->max_level = new_node->size;
  }

  Node *x = list->head;
  int k = list->max_level - 1;

  for (; k >= 0; k--)
  {
    //<0 item1<item2
    if (x->next[k] == NULL || (list->compare(item, x->next[k]->item)) < 0)
    {
      if (k < new_node->size)
      {
        new_node->next[k] = x->next[k];
        x->next[k] = new_node;
      }
    }
    else
    {
      x = x->next[k];
      //così annullo l'effetto del -- nel for per controllare allo stesso livello
      k++;
    }
  }
}

// This is a private method to the API
// It has a fondamental purpose to create a sentinel(Skiplist + Node) that will point to the entire skiplist data structure
// It returns a pointer to the sentinel
Node *create_sentinel(void)
{
  Node *sentinel;
  sentinel = (Node *)malloc(sizeof(Node));
  sentinel->item = NULL;
  sentinel->size = MAX_HEIGHT;
  sentinel->next = (Node **)calloc(MAX_HEIGHT, sizeof(Node *));
  for (int i = 0; i < MAX_HEIGHT; i++)
  {
    sentinel->next[i] = NULL;
  }

  return sentinel;
}

SkipList *create_skiplist(int (*compare_criteria)(void *, void *))
{
  SkipList *list;
  list = (SkipList *)malloc(sizeof(SkipList));
  list->head = create_sentinel();
  list->max_level = 1;
  list->compare = compare_criteria;

  return list;
}

void free_memory_skiplist(SkipList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "free_memory_skiplist: list parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    if (list->head != NULL)
    {
      Node **t = list->head->next;
      Node **p;

      while (t != NULL && t[0] != NULL)
      {
        //mi salvo t[0]->next
        p = t[0]->next;
        free(t[0]->item);
        free(t);
        //metto il valore salvato in p in t perchè il valore precedente di t l'ho completamente eliminato
        t = p;
      }
      free(list->head);
    }
    free(list);
  }
}

int skiplist_is_empty(SkipList *skiplist)
{
  if (skiplist == NULL)
  {
    fprintf(stderr, "skiplist_is_empty: skiplist parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  if (skiplist->head->next[0] == NULL)
  {
    return 1;
  }
  return 0;
}

int skiplist_size(SkipList *skiplist)
{
  if (skiplist == NULL)
  {
    fprintf(stderr, "skiplist_size: skiplist parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  int i = 0;
  Node *temp = skiplist->head->next[0];
  while (temp != NULL)
  {
    i++;
    temp = temp->next[0];
  }
  return i;
}
