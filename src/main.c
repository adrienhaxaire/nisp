#include <stdio.h>
#include <string.h>

#include "repl.h"

int main(int argc, char **argv) {

  if (argc == 1) {
    printf("no arg given"); // or version
  } else if (argc == 2) {
    if (strcmp(argv[1], "repl") == 0) {
      int exit_code = repl();
      return exit_code;
    } else {
      // continue parsing input for files, options, etc
    }
  }
  
  return 0;
}
