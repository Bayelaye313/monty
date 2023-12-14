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
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
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
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		arg.content = content;
		linenum++;
		if (read_line > 0)
		{
			execute(content, &stack, linenum, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
