#ifndef BUILTINS_H
#define BUILTINS_H

#include "info.h"
#include "io.h"
#include "helper_func.h"
#include "memory.h"
#include "execute.h"

/* builtins.c */
int builtins(info_t *info, char **args);
int check_builtins(info_t *info, char **args);

/* builtins_exit.c */
void _exit_builtin(info_t *info, char **args);
int num_controller(info_t *info, char *number);

/* builtins_env.c */
void _env_builtin(info_t *info, char **args);

/* builtins_cd.c */
void _cd_builtin(info_t *info, char **args);

/* builtins_echo.c */
void bin_echo(info_t *info, char **args);
void echo_printer(int index, char *text, char **args);

#endif /* BUILTINS_H */
