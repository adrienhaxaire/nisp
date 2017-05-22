#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "repl.h"
#include "scanner.h"
#include "parser.h"


int add2(int n, int m) {
    return n+m;
}

int main(int argc, char **argv) {
  int exit_code = 0;

  if (argc == 1) {
    printf("no arg given"); // or version
  } else if (argc == 2) {
    if (strcmp(argv[1], "repl") == 0) {
      exit_code = repl();
    } else if (strcmp(argv[1], "test") == 0) {

      char buffer[] = "(+ 1 ( * 22 333  ))";

      struct list_t* lexemes = scan(buffer);
      struct sexp_t* sexp = parse(lexemes);

      // struct list_t it = *lexemes;
      // for (;;) {
      //   printf("value: %s \n", (char*) it.value);
      //   if (it.next == NULL) break;
      //   it = *it.next;
      // }

      int (*a)(int,int);
      // a = (int*)(int,int)(it->value);
      a = sexp->fn;
      struct list_t* it = sexp->args;
      int two = (intptr_t)(it->value);
      it = it->next;
      int three = (intptr_t)(it->value);
      int res = (*a)(two, three);

      printf("eval: %d \n", res);
      
      // free the sexp

    } else {
      // continue parsing input for files, options, etc
    }
  }
  
  return exit_code;
}
