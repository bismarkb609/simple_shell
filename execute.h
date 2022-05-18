#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "error.h"
#include "builtins.h"
#include "info.h"
#include "memory.h"
#include "io.h"
#include "helper_func.h"
#include "env.h"


/* execute_analyzer.c */
void analyze(info_t *info, char **args, char *buff);

/* execute_permissions.c */
int is_executable(char *filename);
int is_file(char *file);
int exe_current_dir(info_t *info, char *cmd, char **args, char *buff);

/* execute.c */
void execute(info_t *info, char *cmd, char **args, char *buff);

#endif /* EXECUTE_H */
