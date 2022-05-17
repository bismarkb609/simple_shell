#include "rktsh.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
unsigned int var_length;
unsigned int i;

var_length = _strlen(variable);

if (var_length != length)
return (-1);

i = 0;

while (name[i] != '\0' && variable[i] != '\0')
{
if (name[i] != variable[i])
return (1);
i++;
}
return (0);
}


/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
unsigned int i;

i = 0;
while (i < length)
{
if (name[i] != variable[i])
return (-1);
i++;
}
return (1);
}

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @des: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *des, char *src)
{
int i;
int j = _strlen(src);

for (i = 0; i <= j; i++)
des[i] = src[i];

return (des);
}

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(char *s)
{
int i = 0;

while (s[i] != '\0')
i++;

return (i);
}

/**
 * _itoa - returns the length of a string
 * @num: The intger value
 * @base: The base of the number
 * Return: the integer in string
 */
char *_itoa(long int num, int base)
{
static char *array = "0123456789abcdef";
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (num < 0)
{
n = -num;
sign = '-';
}
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}
