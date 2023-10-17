#include "monty.h"

/**
 * _err1 - Prints appropiate error messages determined by their error code.
 * @_error_code: The error codes
  */
void _err1(int _error_code, ...)
{
	va_list ag;
	char *op1;
	int l_numer;

	va_start(ag, _error_code);
	switch (_error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_numer = va_arg(ag, int);
			op1 = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_numer, op1);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	_free_nodes1();
	exit(EXIT_FAILURE);
}

/**
 * _more_err1 - handles errors.
 * @_error_code: The error codes
 */
void _more_err1(int _error_code, ...)
{
	va_list ag;
	char *op1;
	int l_numer;

	va_start(ag, _error_code);
	switch (_error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_numer = va_arg(ag, unsigned int);
			op1 = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_numer, op1);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	_free_nodes1();
	exit(EXIT_FAILURE);
}

/**
 * _string_err1 - handles errors.
 * @_error_code: The error codes
 */
void _string_err1(int _error_code, ...)
{
	va_list ag;
	int l_numer;

	va_start(ag, _error_code);
	l_numer = va_arg(ag, int);
	switch (_error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_numer);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_numer);
			break;
		default:
			break;
	}
	_free_nodes1();
	exit(EXIT_FAILURE);
}

