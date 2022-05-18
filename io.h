#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "info.h"
#include "memory.h"
#include "execute.h"
#include "helper_func.h"
#include "io.h"


/* io_patterns.c */
void analyze_patterns(info_t *info, char **args);
char *pattern_handler(info_t *info, char *s);
char *replace_val(info_t *info, int *index, char *s);

/* io_patterns_replacer.c */
char *_replace(info_t *info, int *index, char *s);
char *_set_env(info_t *info, char *env_);

/* io_writers.c */
int _write_char(char c);
int _write(char *msg);
int _write_err(char *msg);
int _write_char_fd(char c, int fd);
int _write_fd(char *msg, int fd);

/* io_tekenization.c */
void prompt(info_t *info);
char *read_prompt();
void start_prompt(info_t *info);
void sigintHandler(int sig_num);

/* io_tekenization.c */
char *join_words(char *str1, char *str2, char *str3, const char *sep);
char **split_words(char *line, const char *sep);

#endif /* IO_H */
