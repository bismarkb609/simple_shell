#include "error.h"


/**
 * msg_selector - Select the message that match with the error_code
 * @info: General information about the shell
 * Return: Error message
 **/
char *msg_selector(info_t info)
{
int i, n_opts;
error_t msgs[] = {
{_ENOENT, _CODE_ENOENT},
{_EACCES, _CODE_EACCES},
{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
};

n_opts = sizeof(msgs) / sizeof(msgs[0]);
for (i = 0; i < n_opts; i++)
if (info.error_code == msgs[i].code)
return (msgs[i].message);

return ("");
}

/**
 * error - Print the error
 *
 * @info: General information about the shell
 **/
void error(info_t *info)
{
char *msg, *num, *str;
int num_len, msg_len;

num = NULL;
msg = msg_selector(*info);
num = _itoa(info->n_commands);

num_len = _strlen(num);
msg_len = _strlen(info->argv[0]);

str = malloc(msg_len + num_len + 3);
str = _strcpy(str, info->argv[0]);
str = _strcat(str, ": ");
str = _strcat(str, num);

msg = join_words(str, info->command, msg, ": ");
_write_err(msg);

free(msg);
free(num);
free(str);
}

/**
 * error_extra - Print the error with extra information
 *
 * @info: General information about the shell
 * @extra: Extra information
 **/
void error_extra(info_t *info, char *extra)
{
char *msg, *num, *str, *str2;
int num_len, msg_len, extra_len;

num = NULL;
msg = msg_selector(*info);
num = _itoa(info->n_commands);

num_len = _strlen(num);
msg_len = _strlen(info->argv[0]);
extra_len = _strlen(extra);

str = malloc(msg_len + num_len + 3);
str = _strcpy(str, info->argv[0]);
str = _strcat(str, ": ");
str = _strcat(str, num);

str2 = malloc(_strlen(msg) + extra_len + 3);
str2 = _strcpy(str2, msg);
str2 = _strcat(str2, ": ");
str2 = _strcat(str2, extra);

msg = join_words(str, info->command, str2, ": ");
_write_err(msg);

free(msg);
free(num);
free(str);
free(str2);
}
