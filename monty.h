#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

/*--- Struct Definitions ---*/
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
	void (*f)(stack_t **stack, unsigned int linenum);
} instruction_t;


/**
* struct arg_s - variables -args, file, line content
* @tok: value
* @script: pointer to monty file
* @content: line content
* @linenum: flag change stack <-> queue
*
* Description: carries values through the program
*/
typedef struct arg_s
{
	char *tok;
	FILE *script;
	char *content;
	int linenum;
}  arg_t;
extern arg_t arg;

/*main func*/
void free_arguments(void);
void validate_arguments(int argc, char *argv[]);
void init_args(void);
void get_script(char *filename);
char *parse_line(char *line);
int run(char *content, stack_t **top, unsigned int linenum, FILE *script);



/* opstack.c */
void _push(stack_t **top, unsigned int linenum);
void _pop(stack_t **top, unsigned int linenum);
void _swap(stack_t **top, unsigned int linenum);
void _rotl(stack_t **top, unsigned int linenum);
void _rotr(stack_t **top, __attribute__((unused)) unsigned int linenum);

/* opprint.c */
void _pall(stack_t **top, unsigned int linenum);
void _pint(stack_t **top, unsigned int linenum);
void _pchar(stack_t **top, unsigned int linenum);
void _pstr(stack_t **top, unsigned int linenum);

/* opmath.c */
void _add(stack_t **top, unsigned int linenum);
void _sub(stack_t **top, unsigned int linenum);
void _div(stack_t **top, unsigned int linenum);
void _mul(stack_t **top, unsigned int linenum);
void _mod(stack_t **top, unsigned int linenum);


char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void _nop(stack_t **top, unsigned int linenum);
void free_stack(stack_t *top);
void addnode(stack_t **top, int n);
void addqueue(stack_t **top, int n);
void _queue(stack_t **top, unsigned int linenum);
void _stack(stack_t **top, unsigned int linenum);
#endif
