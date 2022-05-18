
#include "io.h"

/**
 * _write_char - Print a character to STDOUT
 * @c: Character to print
 * Return: On success 1
 * On error -1
 **/
int _write_char(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * _write - Print a message to STDOUT
 * @msg: Message to print
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int _write(char *msg)
{
	return (_write_fd(msg, STDOUT));
}

/**
 * _write_err - Print a message to STDERR
 * @msg: Message to print
 * Return: Number of bytes printed
 **/
int _write_err(char *msg)
{
	return (_write_fd(msg, STDERR));
}

/**
 * _write_char_fd - Print a character to a specific file
 * descriptor
 * @c: Character to print
 * @fd: Place to print the character
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _write_char_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * _write_fd - Print a string
 * @msg: Strin to print in the fd specified
 * @fd: File descriptor to print
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _write_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}
