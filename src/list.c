#include "list.h"

void append(struct cell **list, char* word) {
  if (*list == NULL) {
    struct cell *cell = malloc(sizeof(struct cell));
    cell->value = malloc(strlen(word));
    strncpy(cell->value, word, strlen(word));
    cell->next = NULL;
    *list = cell;
  } else if ((*list)->next != NULL) {
    append(&((*list)->next), word);
  } else {
    struct cell *next = malloc(sizeof(struct cell));
    next->value = word;
    next->next = NULL;
    (*list)->next = next;
  }
}
