#include "monty.h"

/**
 * _open_file1 - opens a file
 * @_file_name: the file namepath
 * Return: void
 */

void _open_file1(char *_file_name)
{
	FILE *fd = fopen(_file_name, "r");

	if (_file_name == NULL || fd == NULL)
		_err1(2, _file_name);

	_read_file1(fd);
	fclose(fd);
}


/**
 * _read_file1 - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void _read_file1(FILE *fd)
{
	int _line_number, formatf = 0;
	char *_buffer = NULL;
	size_t lenth = 0;

	for (_line_number = 1; getline(&_buffer, &lenth, fd) != -1; _line_number++)
	{
		formatf = _parse_line1(_buffer, _line_number, formatf);
	}
	free(_buffer);
}


/**
 * _parse_line1 - Separates each line into tokens to determine
 * which function to call
 * @_buffer: line from the file
 * @_line_number: line number
 * @formatf:  storage formatf. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int _parse_line1(char *_buffer, int _line_number, int formatf)
{
	char *opcode, *_value;
	const char *_delim = "\n ";

	if (_buffer == NULL)
		_err1(4);

	opcode = strtok(_buffer, _delim);
	if (opcode == NULL)
		return (formatf);
	_value = strtok(NULL, _delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	_find_func1(opcode, _value, _line_number, formatf);
	return (formatf);
}

/**
 * _find_func1 - find the appropriate function for the opcode
 * @opcode: opcode
 * @_value: argument of opcode
 * @formatf:  storage formatf. If 0 Nodes will be entered as a stack.
 * @lnth: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void _find_func1(char *opcode, char *_value, int lnth, int formatf)
{
	int ind;
	int flags;

	instruction_t func_list[] = {
		{"push", _add_to_stack1},
		{"pall", _print_stack1},
		{"pint", _print_top1},
		{"pop", _pop_top1},
		{"nop", _nop1},
		{"swap", _swap_nodes1},
		{"add", _add_nodes1},
		{"sub", _sub_nodes1},
		{"div", _div_nodes1},
		{"mul", _mul_nodes1},
		{"mod", _mod_nodes1},
		{"pchar", _print_char1},
		{"pstr", _print_str1},
		{"rotl", _rotl1},
		{"rotr", _rotr1},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flags = 1, ind = 0; func_list[ind].opcode != NULL; ind++)
	{
		if (strcmp(opcode, func_list[ind].opcode) == 0)
		{
			_call_fun1(func_list[ind].f, opcode, _value, lnth, formatf);
			flags = 0;
		}
	}
	if (flags == 1)
		_err1(3, lnth, opcode);
}


/**
 * _call_fun1 - Calls the required function.
 * @_func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @_val: string representing a numeric _value.
 * @lnth: line numeber for the instruction.
 * @formatf: formatf specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void _call_fun1(op_func _func, char *op, char *_val, int lnth, int formatf)
{
	stack_t *node;
	int flags;
	int ind;

	flags = 1;
	if (strcmp(op, "push") == 0)
	{
		if (_val != NULL && _val[0] == '-')
		{
			_val = _val + 1;
			flags = -1;
		}
		if (_val == NULL)
			_err1(5, lnth);
		for (ind = 0; _val[ind] != '\0'; ind++)
		{
			if (isdigit(_val[ind]) == 0)
				_err1(5, lnth);
		}
		node = create_node(atoi(_val) * flags);
		if (formatf == 0)
			_func(&node, lnth);
		if (formatf == 1)
			_add_to_queue1(&node, lnth);
	}
	else
		_func(&head, lnth);
}

