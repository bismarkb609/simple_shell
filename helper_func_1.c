#include "helper_func.h"

/**
 * _strlen - Return the length of a string
 * @s: String to calculate length
 * Return: Length of the string
 **/
int _strlen(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
;

return (i);
}

/**
 * _strcpy - Copy a string to another
 * @d: Destination copy
 * @s: Source for copy
 * Return: Return the value of dest
 */
char *_strcpy(char *d, char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
d[i] = s[i];

d[i] = '\0';

return (d);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 * @s: String to copy
 * Return: String copied
 **/
char *_strdup(char *s)
{
int size, i;
char *d;

if (s == NULL)
return (NULL);

size = _strlen(s) + 1;
d = malloc(size *sizeof(char));
if (d == NULL)
return (NULL);

for (i = 0; i < size; i++)
*(d + i) = *(s + i);

return (d);
}

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] != '\0'; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}

return (0);
}

/**
 * _strcat - Concatenates two strings
 *
 * @d: String concatenate
 * @s: Source string
 * Return: A string concatenate
 */
char *_strcat(char *d, char *s)
{
int l, i;

l = _strlen(d);

for (i = 0; s[i] != '\0'; i++, l++)
d[l] = s[i];

d[l] = '\0';

return (d);
}

