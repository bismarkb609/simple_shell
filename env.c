#include "env.h"
/**
 * _getenv_full - Get all the environment
 **/
void _getenv_full(void)
{
char **tmp;
int i;

for (i = 0, tmp = environ; tmp[i] != NULL; i++)
{
_write(tmp[i]);
_write_char('\n');
}
}

/**
 * _getenv - Get a environment variable
 *
 * @name: Environment variable to get
 *
 * Return: On success value of @name
 * On error, NULL
 **/
char *_getenv(const char *name)
{
char **env;
char *aux, *token, *value;
int size;

size = _strlen((char *) name);

for (env = environ; *env; ++env)
{
aux = _strdup(*env);

token = strtok(aux, "=");
if (token == NULL)
{
free(aux);
return (NULL);
}

if (_strlen(token) != size)
{
free(aux);
continue;
}

if (_strcmp((char *) name, aux) == 0)
{
token = strtok(NULL, "=");
value = _strdup(token);

free(aux);
return (value);
}

free(aux);
}

return (NULL);
}


/**
 * is_current_path -	Check the order of the path
 * @path: PATH to check
 * @info: General infor about the shell
 **/
void is_current_path(info_t *info, char *path)
{
info->is_current_path = _FALSE;

if (path == NULL)
return;

if (path[0] == ':')
info->is_current_path = _TRUE;
}

/**
 * _which - Find the directory needed
 * @filename: Command received
 * @info: General info about the shell
 * Return: pointer string with found path or NULL in failure.
 */
char *_which(info_t *info, char *filename)
{
char *path, *tmp_path, *token;
char *slash;
int size;

(void) info;

path = _getenv("PATH");
if (path == NULL)
return (NULL);

token = strtok(path, ":");

size = _strlen(filename) + 2;
slash = malloc(size *sizeof(char));
slash = _strcpy(slash, "/");
slash = _strcat(slash, filename);

while (token != NULL)
{
tmp_path = malloc(_strlen(token) + size);
tmp_path = _strcpy(tmp_path, token);
tmp_path = _strcat(tmp_path, slash);

if (is_executable(tmp_path) == PERMISSIONS)
{
free(slash);
free(path);
return (tmp_path);
}
token = strtok(NULL, ":");

free(tmp_path);
}

free(path);
free(slash);

return (NULL);
}
