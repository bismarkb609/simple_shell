#include "rktsh.h"

/**
 * shell_loop - Loops getting input and executing it.
 */
void shell_loop(void)
{
char *line;
char **args;
int status;

do {
write(STDOUT_FILENO, RKTSH_PROMPT, _strlen(RKTSH_PROMPT));
line = _read_line();
args = _split_line(line);
status = _execute(args);

free(line);
free(args);
} while (status);
}


/**
 * main - Starting function of shell
 * Return: Status code
 */
int main(void)
{
shell_loop();
return (EXIT_SUCCESS);
}
