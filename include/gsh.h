#ifndef GSH_H
#define GSH_H

#define GSH_RL_BUFSIZE 1024
#define GSH_TOK_BUFSIZE 64
#define GSH_TOK_DELIM " \t\r\n\a"

/* Built-in command registry */
extern char *builtin_str[];
extern int (*builtin_func[])(char **);

int gsh_num_builtins(void);

/* Built-in command implementations */
int gsh_cd(char **args);
int gsh_help(char **args);
int gsh_exit(char **args);

/* Shell loop and input parsing */
void gsh_loop(void);
char *gsh_read_line(void);
char **gsh_split_line(char *line);

/* Process launching and command dispatch */
int gsh_launch(char **args);
int gsh_execute(char **args);

#endif /* GSH_H */
