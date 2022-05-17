#ifndef RKTSH_H
#define RKTSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "builtins.h"


#define RKTSH_RL_BUFSIZE 1024
#define RKTSH_TOK_BUFSIZE 256
#define RKTSH_TOK_DELIM " \t\r\n\a"

#define RKTSH_DICT_LEN 256

/* prompt string */
#define RKTSH_PROMPT "🚀 ►► "

/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"

extern char **environ;

/* helper functions */
/* void _puts(char *str); */
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);
char *_itoa(long int num, int base);
int _atoi(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
unsigned int word_count(char *str);


char *_read_line(void);
char *search_token(char *string, char *delim);
char **_split_line(char *line);
char **parser(char *str);
int _execute(char **args);
int _launch(char **args);


char *_getenv(const char *name);
char **copy_env(char **environ_cpy, unsigned int environ_len);

#endif /* RKTSH_H */
