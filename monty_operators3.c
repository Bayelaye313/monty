#include "monty.h"

/**
* _pop - function that prints the top of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void _pop(stack_t **top, unsigned int counter)
{
	stack_t *h;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	*top = h->next;
	free(h);
}

/**
* _pint - function that prints the top of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void _pint(stack_t **top, unsigned int counter)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
* _nop - function that does nothing
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void _nop(stack_t **top, unsigned int counter)
{
	(void) counter;
	(void) top;
}
