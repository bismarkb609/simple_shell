#include "rktsh.h"

/**
 * _read_line - Read a line of input from stdin.
 * Return: The line from stdin.
 */

char *_read_line(void)
{
int bufsize = RKTSH_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
error(3);
exit(EXIT_FAILURE);
}
while (1)
{
c = _getchar();
if (c == EOF)
{
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;

if (position >= bufsize)
{
bufsize += RKTSH_RL_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
error(3);
exit(EXIT_FAILURE);
}
}
}
}

