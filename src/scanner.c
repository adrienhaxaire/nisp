#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "grammar.h"
#include "scanner.h"

char* readWord(FILE *stream) {

  int ch;
  char lexeme[2048];
  char* word = NULL;
  size_t cnt = 0;

  while (1) {

    ch = fgetc(stream);

    if ((ch == EMPTY) || (ch == RIGHT)) {
      word = malloc(cnt);
      strncpy(word, lexeme, cnt);
      return word;
    }

    lexeme[cnt] = ch;
    cnt++;
    
  }

  return NULL;
}

int scan(char *source) {

  int character;
  FILE *stream;

  int opened = 0;
  int closed = 0;

  //  char **sexp;
  //  char *word;

  char *plus = NULL;
  char *one = NULL;
  char *two = NULL;

  stream = fmemopen(source, strlen(source), "r");
  while ((character = fgetc(stream)) != EOF) {
    if (character == LEFT) {
      opened++;
      plus = readWord(stream);
      printf("plus: %s\n", plus);
      one = readWord(stream);
      printf("one: %s\n", one);
      two = readWord(stream);
      printf("two: %s\n", two);
    }
    if (character == RIGHT) closed++;
  }
  fclose(stream);

  if (opened - closed != 0) {
    printf("opened: %d, closed: %d\n", opened, closed);
    return 1;
  }
  
  return 0;
}
