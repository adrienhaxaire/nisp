#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>

struct list_t {
  void* value;
  struct list_t* next;
};

void append(struct list_t **list, void* value);

#endif
