#include "io.h"

/**
 * split_words - Split a line into words
 * @line: Line to spli
 * @sep: Delimiters for split the words
 * Return: Set of words
 **/
char **split_words(char *line, const char *sep)
{
char **words, **tmp, *token;
size_t new_size, old_size;
old_size = sizeof(char *);
words = malloc(old_size);
if (words != NULL)
{
new_size = 1;
token = strtok(line, sep);
while (token)
{
if (token[0] == '#')
break;
tmp = _realloc(words, old_size, (new_size + 1) * sizeof(char *));
old_size = (new_size + 1) * sizeof(char *);

if (tmp == NULL)
break;

words = tmp;
++new_size;
words[new_size - 2] = malloc(_strlen(token) + 1);
if (words == NULL)
{
free(tmp);
free(words);
}

if (words[new_size - 2] != NULL)
_strcpy(words[new_size - 2], token);

token = strtok(NULL, sep);
tmp = NULL;
}
words[new_size - 1] = NULL;
}
return (words);
}


/**
 * join_words - Join 3 words with a separator
 * @str1: Word1 to join
 * @str2: Word2 to join
 * @str3: Word3 to join
 * @sep: Separator between the words
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *join_words(char *str1, char *str2, char *str3, const char *sep)
{
char *str;
int size_str1, size_str2, size_str3, size_sep;

size_str1 = size_str2 = size_str3 = size_sep = 0;

if (str1 != NULL)
size_str1 = _strlen(str1);
else
str1 = "";

if (str2 != NULL)
size_str2 = _strlen(str2);
else
str2 = "";

if (str3 != NULL)
size_str3 = _strlen(str3);
else
str3 = "";

if (sep != NULL)
size_sep = _strlen((char *) sep);
else
sep = "";

str = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);

if (str == NULL)
return (NULL);

str = _strcpy(str, str1);
str = _strcat(str, (char *) sep);
str = _strcat(str, str2);
str = _strcat(str, (char *) sep);
str = _strcat(str, str3);
str = _strcat(str, "\n");

return (str);
}

