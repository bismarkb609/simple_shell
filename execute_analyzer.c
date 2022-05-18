#include "execute.h"

/**
 * analyze - Analyze the arguments
 * @args: Commands and arguments to execute
 * @info: General information about the shell
 * @buff: Line readed
 **/
void analyze(info_t *info, char **args, char *buff)
{
char *cmd;
int status;

if (*args == NULL || args == NULL)
return;

cmd = args[0];
info->command = cmd;
if (check_builtins(info, args) == _TRUE)
return;

status = is_file(cmd);
if (status == NON_PERMISSIONS)
{
info->status_code = 126;
info->error_code = _CODE_EACCES;
error(info);
return;
}

if (status == 1)
{
execute(info, cmd, args, buff);
return;
}

if (exe_current_dir(info, cmd, args, buff) == _TRUE)
return;

info->value_path = _which(info, cmd);
if (info->value_path != NULL)
{
execute(info, info->value_path, args, buff);
free_p((void *) info->value_path);
return;
}

info->status_code = 127;
info->error_code = _CODE_CMD_NOT_EXISTS;
error(info);
}

