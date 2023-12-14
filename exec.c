#include "monty.h"

/**
 * validate_arguments - Validates the command-line arguments.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 */
void validate_arguments(int argc, char *argv[])
{
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * init_args - Initializes the global argument structure.
 */
void init_args(void)
{
	arg.tok = NULL;
	arg.script = NULL;
	arg.content = NULL;
	arg.linenum = 0;
}

/**
 * get_script - Opens and sets the script file.
 * @filename: Name of the file to open.
 */
void get_script(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	arg.script = file;
}
/**
 * free_arguments - Frees memory allocated for arguments.
 */
void free_arguments(void)
{
	free(arg.tok);
	free(arg.content);
}


/**
 * get_instruction - Executes the appropriate opcode function.
 * @op: The opcode to execute.
 * @top: Head of the stack linked list.
 * @linenum: Line number.
 */
void get_instruction(char *op, stack_t **top, unsigned int linenum);
void get_instruction(char *op, stack_t **top, unsigned int linenum)
{
	instruction_t opst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL}
	};

	unsigned int i = 0;

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(top, linenum);
			return;
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, op);
		fclose(arg.script);
		free_arguments();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}
