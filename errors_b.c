#include "shell.h"

/**
* _str_atoi - This converts a string to an integer
* @s: This is the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
int _str_atoi(char *s)
{
	int i = 0;

	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
* print_error_msg - This prints an error message
* @info: This is the parameter & return info struct
* @estr: This is the string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error_msg(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_dec(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
* print_dec - This function prints a decimal (integer) number (base 10)
* @input: This is the input
* @fd: This is the filedescriptor to write to
* Return: number of characters printed
*/
int print_dec(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;

	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
* convert_number_c - This converter function, a clone of itoa
* @num: The number
* @base: The base
* @flags: The  argument flags
* Return: string
*/
char *convert_number_c(long int num, int base, int flags)
{
	static char *array;

	static char buffer[50];

	char sign = 0;

	char *ptr;

	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
* comment_remover - This function replaces first instance of '#' with '\0'
* @buf: This is address of the string to modify
* Return: Always 0;
*/
void comment_remover(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
