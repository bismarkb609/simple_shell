#include "execute.h"

/**
 * is_executable - Check if a filename have permissions
 * for run
 * @filename: Filename to check
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 **/
int is_executable(char *filename)
{
struct stat stats;

if (stat(filename, &stats) == 0)
{
if (stats.st_mode & X_OK)
return (PERMISSIONS);
else
return (NON_PERMISSIONS);
}

return (NON_FILE);
}

/**
 * is_file - Check if is a file or binary
 * Description: Looks for excute permissions and
 * if is a file
 * @file: File to check
 * Return: If is a file with the correct permissions, PERMISSIONS
 * If is a file but not have permissions or doesn't exists, NON_PERMISSIONS
 * If is not a file, NON_FILE
 **/
int is_file(char *file)
{
int i, size;

size = _strlen(file);
for (i = 0; i < size; i++)
if (file[i] == '/')
return (is_executable(file));

return (NON_FILE);
}

/**
 * exe_current_dir - Execute the command if the order require
 * @cmd: Command to execute
 * @args: Arguments of the @cmd
 * @buff: Line readed
 * @info: General info about the shell
 * Return: Status of the operations
 **/
int exe_current_dir(info_t *info, char *cmd, char **args, char *buff)
{
if (info->is_current_path == _FALSE)
return (_FALSE);

if (is_executable(cmd) == PERMISSIONS)
{
execute(info, cmd, args, buff);
return (_TRUE);
}

return (_FALSE);
}
