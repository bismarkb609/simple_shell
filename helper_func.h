#ifndef HELPER_FUNC_H
#define HELPER_FUNC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "info.h"
#include "memory.h"
#include "io.h"

/* helper_func_1.c */
int _strlen(char *s);
char *_strcpy(char *d, char *s);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *d, char *s);

/* helper_func_2.c */
char *_itoa(int n);
int is_num(unsigned int n);
int _atoi(char *s);
int has_char(char *s);
int digits(int n);


#endif /* HELPER_FUNC_H */







