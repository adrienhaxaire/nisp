#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>

struct cell {
  char* value;
  struct cell* next;
};

void append(struct cell **list, char* word);

#endif
