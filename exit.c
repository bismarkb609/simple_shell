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
fprintf(stderr, "rktsh: expected no argument to \"CDDD\"\n");
}
return (0);
}
