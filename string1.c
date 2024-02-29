#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination location
 * @src: the source location
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int counter = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the repeated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int counter = 0;

	if (!str)
		return;
	while (str[counter] != '\0')
	{
		_putchar(str[counter]);
		counter++;
	}
}

/**
 * _putchar - writes the character c to standard output
 * @c: The character to print
 * Return: On success 1,on error -1
 */
int _putchar(char c)
{
	static int counter;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || counter >= WRITE_BUF_SIZE)
	{
		write(1, buf, counter);
		counter = 0;
	}
	if (c != BUF_FLUSH)
		buf[counter++] = c;
	return (1);
}
