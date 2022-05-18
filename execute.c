#include "execute.h"

/**
 * execute - Execute a command in other process
 * @cmd: Command to execute
 * @args: Arguments of the @command
 * @info: General info about the shell
 * @buff: Line readed
 **/
void execute(info_t *info, char *cmd, char **args, char *buff)
{
int status;
pid_t pid;

pid = fork();
if (pid == 0)
{
execve(cmd, args, environ);
perror("./sh");

free_pp((void *) args);

if (info->value_path != NULL)
{
free(info->value_path);
info->value_path = NULL;
}

free(info);
free(buff);
exit(1);

}
else if (pid > 0)
{
waitpid(pid, &status, 0);
if (WIFEXITED(status))
info->status_code = WEXITSTATUS(status);
}
}
