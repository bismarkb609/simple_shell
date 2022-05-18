#include "memory.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 *
 * @p: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 *
 * Return: Memory reallocated
 **/
void *_realloc(void *p, size_t old_size, size_t new_size)
{
char *s, *aux;
unsigned int a;

if (new_size == old_size)
return (p);

if (p == NULL)
{
s = malloc(new_size);
if (s == NULL)
return (NULL);

return (s);
}

if (new_size == 0 && p != NULL)
{
free(p);
return (NULL);
}

s = malloc(new_size);
if (s == NULL)
return (NULL);

aux = p;
for (a = 0; a < old_size; a++)
s[a] = aux[a];

free(p);

return (s);
}


/**
 * free_pp - Free a double pointer
 * @pp: Double pointer to free
 **/
void free_pp(void **pp)
{
void **tmp;

for (tmp = pp; *tmp != NULL; tmp++)
free_p(*tmp);

free_p(pp);
}


/**
 * free_p - Free a pointer
 * @p: Pointer to free
 **/
void free_p(void *p)
{
if (p != NULL)
{
free(p);
p = NULL;
}

p = NULL;
}

