#include "rktsh.h"
/**
 * _num_builtins - returns number of builtins
 * Return: number of builtins.
 */
int _num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}
