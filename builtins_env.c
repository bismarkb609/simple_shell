#include "builtins.h"

/**
 * _env_builtin - Implementation for the env builtin
 * @info: General information about the shell
 * @args: Command
 **/

void _env_builtin(info_t *info, char **args)
{
(void) info;
(void) args;
_getenv_full();
}
