#include "rktsh.h"

/**
 * _sptok - splits a string
 * @s: string arg to split
 * @delim: delimiter arg for separator string
 * Return: pointer to char on success, NULL on failure
 */
char *_sptok(char *s, char *delim)
{
static char *rem;
int s_length = 0;
int i = 0;
int lim_s = 0;

if (delim == NULL)
return (NULL);
if ((s == NULL) && (rem == NULL))
return (NULL);
if (s == NULL)
s = rem;
s_length = _strlen(s) + 1;
for (i = 0; i < s_length; i++)
{
if (s[i] == delim[0])
{
lim_s = 1;
break;
}
}
if (lim_s != 1)
{
rem = NULL;
return (s);
}
s[i] = '\0';
if ((s + i + 1) != NULL)
rem = s + i + 1;
else
rem = NULL;
return (s);
}
