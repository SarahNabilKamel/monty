#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void _open_file1(char *_file_name);
int _parse_line1(char *buffer1, int _line_number1, int formatf);
void _read_file1(FILE *);
int _len_chars1(FILE *);
void _find_func1(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void _free_nodes1(void);
void _print_stack1(stack_t **, unsigned int);
void _add_to_stack1(stack_t **, unsigned int);
void _add_to_queue1(stack_t **, unsigned int);

void _call_fun1(op_func, char *, char *, int, int);

void _print_top1(stack_t **, unsigned int);
void _pop_top1(stack_t **, unsigned int);
void _nop1(stack_t **, unsigned int);
void _swap_nodes1(stack_t **, unsigned int);

/*Math operations with nodes*/
void _add_nodes1(stack_t **, unsigned int);
void _sub_nodes1(stack_t **, unsigned int);
void _div_nodes1(stack_t **, unsigned int);
void _mul_nodes1(stack_t **, unsigned int);
void _mod_nodes1(stack_t **, unsigned int);

/*String operations*/
void _print_char1(stack_t **, unsigned int);
void _print_str1(stack_t **, unsigned int);
void _rotl1(stack_t **, unsigned int);

/*Error hanlding*/
void _err1(int _error_code, ...);
void _more_err1(int _error_code, ...);
void _string_err1(int _error_code, ...);
void _rotr1(stack_t **, unsigned int);

#endif

