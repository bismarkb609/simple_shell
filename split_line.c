#include "rktsh.h"

/**
 * _split_line - function for splitting a line into tokens (very naively).
 * @line: Character to split
 * Return: Null-terminated array of tokens.
 */
char **_split_line(char *line)
{
int bufsize = RKTSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;

if (!tokens)
{
fprintf(stderr, "rktsh: allocation error\n");
exit(EXIT_FAILURE);
}

token = _sptok(line, RKTSH_TOK_DELIM);

while (token != NULL)
{
printf("Token no. %d : %s \n", position, token);
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += RKTSH_TOK_BUFSIZE;
tokens_backup = tokens;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
free(tokens_backup);
fprintf(stderr, "rktsh: allocation error\n");
exit(EXIT_FAILURE);
}
}

token = _sptok(NULL, RKTSH_TOK_DELIM);

}

tokens[position] = NULL;

return (tokens);
}

