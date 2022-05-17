#include "rktsh.h"


/**
* _env - prints environment
* @args: List of args.  Not examined.
* Return: void
**/
int _env(char **args)
{
unsigned int i;
i = 0;

if (args[0] == NULL)
{
return (1);
}

while (environ[i] != NULL)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}

return (1);
}
