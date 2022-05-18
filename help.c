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
write(STDERR_FILENO, "rktsh: expected no argument to \"help\"\n", 39);
}

write(STDOUT_FILENO, "RocKeT SHell - RKTSH\n", 22);
write(STDOUT_FILENO, "Type program names and arguments, and hit enter.\n", 50);
write(STDOUT_FILENO, "The following are built in:\n", 29);

for (i = 0; i < _num_builtins(); i++)
{
write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
write(STDOUT_FILENO, "\n", 2);
}

write(STDOUT_FILENO, "\n", 2);
write(1, "Use the man command for information on other programs.\n\n", 57);
return (1);
}
