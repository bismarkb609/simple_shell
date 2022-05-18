#include "rktsh.h"

/**
 * _exit_ - Builtin command: exit.
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int _exit_(char **args)
{
if (args[1] != NULL)
{
error(4);
}
return (0);
}
