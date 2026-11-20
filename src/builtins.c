#include <stdio.h>
#include <unistd.h>

#include "gsh.h"

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[])(char **) = {
  &gsh_cd,
  &gsh_help,
  &gsh_exit
};

int gsh_num_builtins(void)
{
  return sizeof(builtin_str) / sizeof(char *);
}

int gsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "gsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("gsh");
    }
  }
  return 1;
}

int gsh_help(char **args)
{
  int i;
  (void)args;

  printf("gabby's gsh!!!!!!!\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < gsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int gsh_exit(char **args)
{
  (void)args;
  return 0;
}
