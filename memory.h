#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

/* memory.c */
void *_realloc(void *p, size_t old_size, size_t new_size);
void free_p(void *p);
void free_pp(void **pp);

#endif /* MEMORY_H */
