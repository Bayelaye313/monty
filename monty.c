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
	stack_t *stack = NULL;

	validate_arguments(argc, argv);
	read_file(argv[1], &stack);
	free_stack(stack);
return (0);
}
