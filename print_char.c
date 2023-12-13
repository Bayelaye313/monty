#include "monty.h"

/**
* f_pchar - function that prints the char at the top of the stack,
* followed by a new line
* @top: stack top
* @counter: line count
*
* Return: nothing
*/
void f_pchar(stack_t **top, unsigned int counter)
{
	stack_t *h;

	h = *top;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
