#include "helper_func.h"

/**
 * _itoa - Conver @number to string
 * @n: Number to convert
 * Return: Number as string
 **/
char *_itoa(int n)
{
int n_digits, i;
char *_number;

n_digits = digits(n);
_number = malloc(n_digits *sizeof(char) + 2);
if (n == 0)
{
_number[0] = '0';
_number[1] = '\0';
return (_number);
}

_number[n_digits] = '\0';
for (i = n_digits - 1; n != 0; n /= 10, i--)
_number[i] = (n % 10) + '0';

return (_number);
}


/**
 * is_num - Check if is a digit
 * @n: Number
 * Return: If is a number, return 1 else return 0
 */
int is_num(unsigned int n)
{
return (n >= '0' && n <= '9');
}

/**
 * _atoi - Convert a string to a number
 * @s: String to convert
 * Return: Return the number
 */
int _atoi(char *s)
{
unsigned int number, i;
int sign;

sign = 1;
number = 0;
for (i = 0; s[i] != '\0'; i++)
{
if (is_num(s[i]))
{
number = (s[i] - 48)	+ number * 10;

if (s[i + 1] == ' ')
break;
}
else if (s[i] == '-')
{
sign *= -1;
}
}

return (number *sign);
}

/**
 * has_char - Search non-digits in a string
 * @s: String for search
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 **/
int has_char(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
if (is_num(s[i]) == 0)
return (1);
}

return (0);
}

/**
 * digits - Count the number of digits of a number
 * @n: Number
 * Return: Digits
 **/
int digits(int n)
{
int i;
for (i = 0; n != 0; i++, n /= 10)
;
return (i);
}
