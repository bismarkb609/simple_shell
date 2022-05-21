#include "builtins.h"
/**
 * _exit_builtin - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 * @info: Information about the shell
 * @args: Arguments received
 **/
void _exit_builtin(info_t *info, char **args)
{
int status_code, status;

status = _TRUE;
if (args[1] != NULL)
status = num_controller(info, args[1]);

if (status == _FALSE)
return;

status_code = info->status_code;

free_pp((void **) args);
free_p((void *) info->buffer);
free_p((void *) info->environment);
free_p((void *) info);

exit(status_code);
}
/**
 * num_controller - Control the argument of exit
 * @info: General information about the shell
 * @num: Argument of the builtin
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 **/
int num_controller(info_t *info, char *num)
{
int _num;

_num = _atoi(num);

if (_num < 0 || has_char(num))
{
info->status_code = 2;
info->error_code = _CODE_ILLEGAL_NUMBER;
error_extra(info, num);
return (_FALSE);
}

if (_num > 255)
info->status_code = _num % 256;
else
info->status_code = _num;

return (_TRUE);
}
