#include "builtins.h"

/**
 * _cd_builtin - Implementation of the cd builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 * @info: Information about the shell
 * @args: Arguments received
 **/
void _cd_builtin(info_t *info, char **args)
{
char *dir;
char *d = NULL;
char cwd[256];
dir = NULL;

printf("current directory is: %s\n", info->current_dir);


if (args[1] == NULL)
{
dir = _getenv("HOME");

d = getcwd(cwd, sizeof(cwd));
printf("d: %s\n", d);
*info->current_dir = *d;
printf("current directory is: %s\n", info->current_dir);
}

else if (_strcmp(args[1], "-") == 0)
{
_strcpy(dir, info->current_dir);
printf("should chdir here: %s\n", dir);
}
else
{
dir = args[1];

d = getcwd(cwd, sizeof(cwd));
*info->current_dir = *d;
printf("current directory is: %s\n", info->current_dir);
}




if (chdir(dir) != 0)
{
error_err(info, _ENOENT);
}

printf("stored directory is: %s\n", info->current_dir);
}

