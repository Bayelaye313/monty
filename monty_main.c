#include "monty.h"
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>

arg_t arg = {NULL, NULL, NULL, 0};

/**
* main - function for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content, *op;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int linenum = 0;

	validate_arguments(argc, argv);
	file = fopen(argv[1], "r");
	arg.script = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
