#include "main.h"

/**
 * main - Entry point of the shell
 *
 * @argc: Number of arguments received
 * @argv: Arguments received
 *
 * Return: 0 on success and 1 on error
 **/
int main(int argc, char **argv)
{
info_t *info;
int status_code;

info = malloc(sizeof(info_t));
if (info == NULL)
{
perror(argv[0]);
exit(1);
}

info->pid = getpid();
info->status_code = 0;
info->n_commands = 0;
info->argc = argc;
info->argv = argv;
info->current_dir = "-";
info->mode = isatty(STDIN) == INTERACTIVE;
start(info);

status_code = info->status_code;

free(info);

return (status_code);
}




/**
 * start - Handle the mode
 * Description: Mode can be INTERACTIVE or NON_INTERACTIVE
 *
 * @info: Struct of information about the shell
 **/
void start(info_t *info)
{
start_prompt(info);
}
