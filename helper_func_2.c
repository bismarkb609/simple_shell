#include "rktsh.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
int number, i, neg;

neg = 1;
i = number = 0;

while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
{
if (s[i] == '-')
neg = neg * -1;
i++;
}

while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
{
if (number >= 0)
{
number = number * 10 - (s[i] - '0');
i++;
}
else
{
number = number * 10 - (s[i] - '0');
i++;
}
}
neg = neg * -1;
return (number *neg);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: String to be duplicated.
 * Return: pointer to newly allocated space in memory
 * containing duplicate string.
 */
char *_strdup(char *str)
{
char *dup;
int i;

if (str == NULL)
return (NULL);

i = 0;

while (str[i])
{
i++;
}

dup = malloc(sizeof(char) * (i + 1));
if (dup == NULL)
{
return (NULL);
}

i = 0;
while (str[i])
{
dup[i] = str[i];
i++;
}

dup[i] = '\0';
return (dup);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
int i, j;

i = 0;
j = 0;

while (dest[i] != '\0')
i++;

while (src[j] != '\0')
{
dest[i] = src[j];
j++;
i++;
}

dest[i] = '\0';

return (dest);
}



/**
 * word_count - counts words given a char delimiter
 * @str: string of words
 * Return: word count as unsigned int
 */
unsigned int word_count(char *str)
{
unsigned int i, wc, flag;
char *delims = "\n \t";

for (i = 0, wc = 1, flag = 0; str[i]; i++)
{
if (flag == 0 &&
(str[i] == delims[0]
|| str[i] == delims[1]
|| str[i] == delims[2])
&& str[i + 1] != delims[0]
&& str[i + 1] != delims[1]
&& str[i + 1] != delims[2])
flag = 1, wc++;
else
flag = 0;
}
return (wc);
}



/**
 * _getchar - Read a line of input from stdin.
 * Return: character from stdin.
 */
int _getchar(void)
{
static char buf[BUFSIZ];
static char *bufp = buf;
static int i;
i = 0;

if (i == 0)
{
i = read(0, buf, 1);
bufp = buf;
}
if (--i >= 0)
{
return  (*bufp++);
}
return (EOF);
}

