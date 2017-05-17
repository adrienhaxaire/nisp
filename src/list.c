#include "list.h"

void append(struct list_t **l, void* value) {
  if (*l == NULL) {
    struct list_t *list = malloc(sizeof(struct list_t));
    list->value = malloc(strlen(value));
    strncpy(list->value, value, strlen(value));
    list->next = NULL;
    *l = list;
  } else if ((*l)->next != NULL) {
    append(&((*l)->next), value);
  } else {
    struct list_t *next = malloc(sizeof(struct list_t));
    next->value = value;
    next->next = NULL;
    (*l)->next = next;
  }
}
