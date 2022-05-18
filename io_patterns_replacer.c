#include "io.h"

/**
 * _replace - Replaces environment with condition
 * @info: General info about the shell
 * @index: index position
 * @s: string
 * Return: char of value
 **/
char *_replace(info_t *info, int *index, char *s)
{
char *tmp;
char symbol;

(void) index;

symbol = *s;
if (symbol != '?' && symbol != '$')
{
tmp = _set_env(info, s);
return (tmp);
}

tmp = (symbol == '$') ? _itoa(info->pid) :
_itoa(info->status_code);

return (tmp);
}


/**
 * _set_env - Replaces environment variable
 * @info: General info about the shell
 * @env_: Environment
 * Return: char of value
 **/
char *_set_env(info_t *info, char *env_)
{
char *env;

(void) info;

env = _getenv(env_);
if (env != NULL)
return (env);

return (NULL);
}

