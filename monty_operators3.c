#include "monty.h"

/**
* f_pop - function that prints the top of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_pop(stack_t **top, unsigned int counter)
{
	stack_t *h;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	*top = h->next;
	free(h);
}

/**
* f_pint - function that prints the top of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_pint(stack_t **top, unsigned int counter)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
* f_nop - function that does nothing
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_nop(stack_t **top, unsigned int counter)
{
	(void) counter;
	(void) top;
}
