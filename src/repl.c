#include <stdio.h>

#include "repl.h"

int repl(void) {
  while (1) {
    fputs("nisp> ", stdout);
    fgets(repl_input, REPL_INPUT_SIZE, stdin);
    printf("echo: %s", repl_input);
  }
  return 0;
}
