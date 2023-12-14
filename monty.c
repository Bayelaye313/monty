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
			run(content, &stack, linenum, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
/**
 * perform_operation - performs the specified arithmetic operation
 * @top: double pointer top to the stack
 * @line_num: line count
 * @operation: function pointer to the arithmetic operation
 *
 * Return: nothing
 */
void perform_operation(stack_t **top, unsigned int line_num,
								void (*operation)(stack_t **, int))
{
	stack_t *h;
	int length = 0;

	h = *top;
	while (h)
	{
		h = h->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	operation(top, line_num);
}
