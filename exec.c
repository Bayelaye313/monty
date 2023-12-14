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
* execute - function that executes the opcode
* @top: head stack linked list
* @linenum: line count
* @script: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute(char *content, stack_t **top, unsigned int linenum, FILE *script);
int execute(char *content, stack_t **top, unsigned int linenum, FILE *script)
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
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	arg.tok = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(top, linenum);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", linenum, op);
		fclose(script);
		free(content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	return (1);
}
