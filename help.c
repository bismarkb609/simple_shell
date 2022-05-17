#include "rktsh.h"

/**
 * _help - Builtin command: print help.
 * @args: List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int _help(char **args)
{
int i;

if (args[2] == NULL)
{
fprintf(stderr, "rktsh: expected no argument to \"help\"\n");
}

printf("RocKeT SHell - RKTSH\n");
printf("Type program names and arguments, and hit enter.\n");
printf("The following are built in:\n");

for (i = 0; i < _num_builtins(); i++)
{
printf("  %s\n", builtin_str[i]);
}

printf("Use the man command for information on other programs.\n");
return (1);
}
