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
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
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
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @top: pointer to the top of the stack
 *
 */
void read_file(char *filename, stack_t **top)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int linenum = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			linenum++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", linenum, line);
			exit(EXIT_FAILURE);
		}
		s(top, linenum);
		linenum++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}
