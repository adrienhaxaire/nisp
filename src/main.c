#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "repl.h"
#include "scanner.h"

int main(int argc, char **argv) {
  int exit_code = 0;

  if (argc == 1) {
    printf("no arg given"); // or version
  } else if (argc == 2) {
    if (strcmp(argv[1], "repl") == 0) {
      exit_code = repl();
    } else if (strcmp(argv[1], "test") == 0) {

      char buffer[] = "(+ 1 41))";
      FILE *stream = fmemopen(buffer, strlen(buffer), "r");
      exit_code = scan(stream);

    } else {
      // continue parsing input for files, options, etc
    }
  }
  
  return exit_code;
}
