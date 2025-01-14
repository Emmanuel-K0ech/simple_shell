#include "shell.h"

/**
* _myhistoryy - This displays the history list, one command by line, preceded
* with line numbers, starting at 0.
* @info: This is the structure containing potential arguments. Used to maintain
* constant function prototype.
*  Return: Always 0
*/
int _myhistoryy(info_t *info)
{
	printt_lists(info->history);
	return (0);
}

/**
* unset_alias - This sets alias to string
* @info: Thsi is the parameter struct
* @str: This is the string alias
*
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	char *p, c;

	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_nodee_at_index(&(info->alias),
							gett_node_index(info->alias, startt_node_is(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
* set_alias - This sets alias to string
* @info: this is the parameter struct
* @str: This is the the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_nodee_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - This prints an alias string
* @node: This is the alias node
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
* _myaliass - This mimics the alias builtin (man alias)
* @info: this is the tructure containing potential arguments. Used to maintain
* constant function prototype.
*  Return: Always 0
*/
int _myaliass(info_t *info)
{
	int i = 0;

	char *p = NULL;

	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(startt_node_is(info->alias, info->argv[i], '='));
	}

	return (0);
}
