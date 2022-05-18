#include "rktsh.h"

/**
 * _cd - Bultin command: change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: Always returns 1, to continue executing.
 */
int _cd(char **args)
{
char *dir;

if (args[1] == NULL)
{
dir = _getenv("HOME");
}
else
{
dir = args[1];
}

if (chdir(dir) != 0)
{
error(2);
}
return (1);
}
