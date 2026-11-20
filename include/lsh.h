#ifndef LSH_H
#define LSH_H

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

/* Built-in command registry */
extern char *builtin_str[];
extern int (*builtin_func[])(char **);

int lsh_num_builtins(void);

/* Built-in command implementations */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

/* Shell loop and input parsing */
void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);

/* Process launching and command dispatch */
int lsh_launch(char **args);
int lsh_execute(char **args);

#endif /* LSH_H */
