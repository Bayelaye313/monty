#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE

arg_t arg = {NULL, NULL, NULL, 0};

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
 * main - Entry point for the Monty code interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: Returns 0 on success.
 */
int main(int argc, char *argv[])
{
	char *content, *op;
	stack_t *stack = NULL;
	unsigned int linenum = 0;

	validate_arguments(argc, argv);
	init_args();
	get_script(argv[1]);

	while (getline(&content, arg.script, &linenum) > 0)
	{
		arg.content = content;
		if (content[0] == '#' || content[0] == '\n')
		{
			free(content);
			continue;
		}

		op = parse_line(content);
		get_instruction(op, &stack, linenum);

		free(content);
	}

	free_stack(stack);
	fclose(arg.script);
	free_arguments();
	return (0);
}
