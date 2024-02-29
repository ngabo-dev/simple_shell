#include "shell.h"

/**
 *_eputs - Prints a string of input
 * @str: A string that will be printed
 *
 * Return: None
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Adds the character C to stderr.
 * @c: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and Error is properly set.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the letter C to the specified fd.
 * @c: The char to print
 * @fd: The descriptive field to use
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is properly set.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - Prints a string of input
 * @str: printes the string
 * @fd: Write the descriptive file
 *
 * Return: adds the number of chars
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
