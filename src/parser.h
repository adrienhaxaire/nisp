#ifndef PARSER_H
#define PARSER_H

#include "list.h"

struct sexp_t* parse(struct list_t* lexemes);

typedef int (*bin_op)(int,int);

struct sexp_t {
  bin_op fn;
  struct list_t* args;
};


#endif 

