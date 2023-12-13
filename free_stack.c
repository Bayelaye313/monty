#include "monty.h"

/**
* free_stack - function that frees a doubly linked list
* @top: top pointer to the stack
*
* Return: nothing
*/
void free_stack(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

/**
* _stack - function that prints the top
* @top: top of stack
* @counter: line count
*
* Return: nothing
*/
void _stack(stack_t **top, unsigned int counter)
{
	(void)top;
	(void)counter;
	arg.linenum = 0;
}
