#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "grammar.h"
#include "scanner.h"
#include "list.h"

void scan_sexp(FILE *stream, struct cell** sexp) {

  char buffer[2048];
  size_t count = 0;
  char ch;
  
  while ((ch = fgetc(stream)) != EOF) {

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

struct cell* scan(FILE *stream) {
  struct cell* sexp = NULL;
  scan_sexp(stream, &sexp);
  return sexp;
}
