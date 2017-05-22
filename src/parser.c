#include "grammar.h"
#include "parser.h"
#include "list.h"

int add(int n, int m) {
    return n+m;
}

struct sexp_t* parse(struct list_t *lexemes) {

  struct sexp_t* sexp = malloc(sizeof(struct sexp_t));
  sexp->fn = &add;
  sexp->args = malloc(sizeof(struct list_t));
  struct list_t *it = sexp->args;
  it->value = (int*)2;
  it->next = malloc(sizeof(struct list_t));
  it = it->next;
  it->value = (int*)3;
  it->next = NULL;

  //append(&(sexp->args), (int*)3);
  
//  struct list_t* sexp = NULL;
//  if (lexemes->value == NULL) return sexp;
//
//  struct list_t* it = lexemes;
//  while (it->next != NULL) {
//    char* symbol = it->value;
//    if (*symbol == LEFT) {
//      it = it->next;
//      append(&sexp, &(it->value));
//      it = it->next;
//    } else if (*((char*) it->value) == RIGHT) {
//      it = it->next;
//    } else {
//      
//    }
//  }

  return sexp;
}
