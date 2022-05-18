#include "rktsh.h"

/**
 * _execute - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int _execute(char **args)
{
int i;

if (args[0] == NULL)
{
/* Empty command was entered */
return (1);
}

for (i = 0; i < _num_builtins(); i++)
{
if (_strcmp(args[0], builtin_str[i], _strlen(args[0])) == 0)
{
return ((*builtin_func[i])(args));
}
}

return (_launch(args));
}



/**
 * _launch - Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments (including program).
 * Return: Always returns 1, to continue execution.
 */
int _launch(char **args)
{
pid_t pid;
int status;

char *path;
char *fullpath;

pid = fork();
if (pid == 0)
{
/* Child process */
path = _getenv("PATH");
fullpath = _which(args[0], path, path);

if (execve(fullpath, args, NULL) == -1)
{
error(2);
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
error(2);
}
else
{
/* Parent process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}
