#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "grammar.h"
#include "scanner.h"
#include "list.h"

char* read_word(FILE *stream, char* lexeme, size_t count) {

  int ch = fgetc(stream);
  if (ch == EOF) return NULL;

  if ((ch == EMPTY) || (ch == RIGHT)) {
    char* word = malloc(count);
    strncpy(word, lexeme, count);
    return word;
  }

  lexeme[count] = ch;
  return read_word(stream, lexeme, count + 1);
}


void scan_sexp(FILE *stream, struct cell** sexp) {
  char lexeme[2048];
  char* word = read_word(stream, lexeme, 0);
  if (strlen(word) != 0) {
    append(sexp, word);
    scan_sexp(stream, sexp);
  }
  //  if (character == RIGHT)
}


int scan(FILE *stream) {

  int opened = 0;
  int closed = 0;

  struct cell* sexp = NULL;
  int character;
  while ((character = fgetc(stream)) != EOF) {
    if (character == LEFT) {
      opened++;
      scan_sexp(stream, &sexp);
    }
    if (character == RIGHT) closed++;
  }
  fclose(stream);

  struct cell it = *sexp;
  for (;;) {
    printf("value: %s \n", it.value);
    if (it.next == NULL) break;
    it = *it.next;
  }
    
  if (opened - closed != 0) {
    printf("opened: %d, closed: %d\n", opened, closed);
    return 1;
  }

  return 0;
}
