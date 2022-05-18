#include "builtins.h"

/**
 * builtins - Check and execute the builtins
 * @info: Information about the shell
 * @args: Commands and arguments
 * Return: If the command passed is a builtins
 * return _TRUE if not return _FALSE
 **/
int builtins(info_t *info, char **args)
{
int status;
status = check_builtins(info, args);
if (status == _FALSE)
return (_FALSE);

return (_TRUE);
}


/**
 * check_builtins - Check if the actual command is a builtin_t
 * or not
 * @info: General information about the shell
 * @args: Commands and arguments
 * Return: If the command is an actual builtin, return _TRUE
 * if not _FALSE
 **/
int check_builtins(info_t *info, char **args)
{
int i, size;
builtin_t builtins[] = {
{"exit", _exit_builtin},
{"env", _env_builtin}
};

size = sizeof(builtins) / sizeof(builtins[0]);
for (i = 0; i < size; i++)
{
if (_strcmp(info->command, builtins[i].command) == 0)
{
builtins[i].func(info, args);
return (_TRUE);
}
}

return (_FALSE);
}

