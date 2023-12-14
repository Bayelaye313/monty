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
 * parse_line - Parses a line for an opcode and arguments.
 * @line: The line to be parsed.
 *
 * Return: Returns the opcode or NULL on failure.
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	return (op_code);
}
/**
 * get_instruction - Exécute la fonction correspondant à l'opcode.
 * @op: L'opcode à exécuter.
 * @top: Tête de la pile.
 * @linenum: Numéro de ligne.
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
			if (opst[i].f != NULL)
				opst[i].f(top, linenum);
			else
				fprintf(stderr, "L%d: function not implemented for %s\n", linenum, op);

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
