#ifndef skiplist_123456
#define skiplist_123456

// this macro defines the height of the levels used to represent skiplist
#define MAX_HEIGHT 16

typedef struct _SkipList SkipList;
typedef struct _Node Node;

struct _SkipList
{
  Node *head;
  int max_level;
  int (*compare)(void *, void *);
};

struct _Node
{
  Node **next;
  int size;
  void *item;
};

// This method implements search function through skiplist
// It accepts two parameters: a pointer to the skiplist data structure that cannot be NULL, and a pointer to the item to be searched
void *search_skiplist(SkipList *list, void *item);

// This method implements insert function into skiplist
// It accepts two parameters: a pointer to the skiplist data structure that cannot be NULL, and a pointer to the item to be stored
void insert_skiplist(SkipList *list, void *item);

// This method helps to create a skiplist data structure
// It accepts only one parameter: comparison criteria because the insertion is not casual but ordered
// it returns a pointer to the created structure
SkipList *create_skiplist(int (*compare_criteria)(void *, void *));

// This method is used to free resources requested by the skiplist
// It accepts only one parameter: the pointer to the skiplist that cannot be NULL to be freed
void free_memory_skiplist(SkipList *list);

// This method is used to check if a skiplist is empty
// It accepts a pointer to the structure that cannot be NULL
// It returns 1 if the skiplist is empty, 0 otherwise
int skiplist_is_empty(SkipList *skiplist);

// This method find the size of the skiplist
// It accepts a pointer to the skiplist that cannot be NULL
// It returns the size of the data structure
int skiplist_size(SkipList *skiplist);

#endif
