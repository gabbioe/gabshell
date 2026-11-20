#include <stdio.h>
#include <stdlib.h>

#include "gsh.h"

void gsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = gsh_read_line();
    args = gsh_split_line(line);
    status = gsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  // Load config files, if any.

  // Run command loop.
  gsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
