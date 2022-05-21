#include "io.h"

/**
 * analyze_patterns - Analyzes patterns
 * @info: General info about the shell
 * @args: Arguments
 **/
void analyze_patterns(info_t *info, char **args)
{
int i;

for (i = 0; args[i] != NULL; i++)
args[i] = pattern_handler(info, args[i]);

}

/**
 * pattern_handler - Handles pattern
 * @s: string as pattern
 * @info: General info about the shell
 * Return: char of value
 **/
char *pattern_handler(info_t *info, char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == '$' && s[i + 1] != '\0')
s = replace_val(info, &i, s);
}

return (s);
}

/**
 * replace_val - Replaces value
 * @s: String
 * @info: General info about the shel
 * @index: Index position
 * Return: char of value
 **/
char *replace_val(info_t *info, int *index, char *s)
{
int i, new_s, old_s;
char *value;

i = *index;
i++;

value = _replace(info, index, s + i);
if (value == NULL)
{
s = _strcpy(s, "");
return (s);
}

old_s = _strlen(s);
new_s = _strlen(value) + 1;

s = _realloc(s, old_s, new_s);
s = _strcpy(s, value);

free_p(value);
*index = i;
return (s);
}
