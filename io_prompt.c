#include "io.h"


/**
 * prompt - Print the prompt
 * @info: Struct of general information
 **/
void prompt(info_t *info)
{
if (info->mode == NON_INTERACTIVE)
return;

_write(SH_PROMPT);
}

/**
 * read_prompt - Read lines in the prompt
 * Return: Buffer readed or NULL if EOF was found
 **/
char *read_prompt()
{
char *buf;
int res;
size_t size;

buf = NULL;

res = getline(&buf, &size, stdin);

if (res == EOF)
{
free_p((void *) buf);
return (NULL);
}

return (buf);
}


/**
 * start_prompt - Loop reading text
 *
 * @info: Struct of general information
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
void start_prompt(info_t *info)
{
char *buff;
char **arguments;
char *path;

signal(SIGINT, sigintHandler);
while (1)
{
prompt(info);

path = _getenv("PATH");
is_current_path(info, path);

info->environment = path;
buff = read_prompt();
if (buff == NULL)
{
_write(info->mode == INTERACTIVE ? "exit\n" : "");
free(path);
break;
}

info->n_commands++;
if (buff[0] != '\n')
{
arguments = split_words(buff, " \t\n");

info->arguments = arguments;
info->buffer = buff;

analyze_patterns(info, arguments);
analyze(info, arguments, buff);

free_pp((void *) arguments);
}

free_p((void *) buff);
free_p((void *) path);
}

}


/**
 * sigintHandler - Handler for SIGINT
 * @sig_num: Unused parameter
 **/
void sigintHandler(int sig_num)
{
(void) sig_num;

signal(SIGINT, sigintHandler);
_write("\n$ ");
fflush(stdout);
}
