#include "shell.h"

/**
* _eputs - this prints an input string
* @str: this is the string to be printed
* Return: Nothing
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
* _eputchar - This  writes the character c to stderr
* @c: This is the character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
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
* _putfd - This writes the character c to given fd
* @c: this is the  character to print
* @fd: This is the filedescriptor to write to
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
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
* _putsfd - This prints an input string
* @str: This is the string to be printed
* @fd: This is the filedescriptor to write to
* Return: the number of chars put
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
