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
if (strcmp(args[0], builtin_str[i]) == 0)
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

pid = fork();
if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("rktsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror("rktsh");
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
