#ifndef ENV_H
#define ENV_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/cdefs.h>


#include "error.h"
#include "builtins.h"
#include "info.h"
#include "memory.h"
#include "io.h"
#include "helper_func.h"
#include "execute.h"

extern char **environ;

/* env.c */
void _getenv_full(void);
char *_getenv(const char *name);
void is_current_path(info_t *info, char *path);
char *_which(info_t *info, char *filename);

#endif /* ENV_H */
