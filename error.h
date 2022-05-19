#ifndef ERROR_H
#define ERROR_H

#include "info.h"
#include "io.h"
#include "helper_func.h"

/* error.c */
char *msg_selector(info_t info);
void error(info_t *info);
void error_extra(info_t *info, char *extra);
void error_err(info_t *info, char *extra);

#endif /* ERROR_H */
