#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "grammar.h"
#include "scanner.h"
#include "list.h"

void scan_sexp(char* input, struct cell** sexp) {
  
  char buffer[2048];
  size_t count = 0;
  char ch;
  
  for (size_t pos=0; pos < strlen(input); pos++) {

    ch = (char) input[pos];

    if (ch == LEFT) {
      char* lexeme = malloc(1);
      lexeme = "(";
      append(sexp, lexeme);
      count = 0;
    } else if (ch == RIGHT) {
      if (count != 0) {
        char* lexeme = malloc(count);
        strncpy(lexeme, buffer, count);
        append(sexp, lexeme);
        count = 0;
      }
      char* lexeme = malloc(1);
      lexeme = ")";
      append(sexp, lexeme);
    } else if (ch == EMPTY) {
      if (count > 0) {
        char* lexeme = malloc(count);
        strncpy(lexeme, buffer, count);
        append(sexp, lexeme);
        count = 0;
      }
    } else {
      buffer[count] = ch;
      count++;
    }
  }
}

struct cell* scan(char *input) {
  struct cell* sexp = NULL;
  scan_sexp(input, &sexp);
  return sexp;
}
