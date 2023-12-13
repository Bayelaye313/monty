#include "monty.h"

/**
* _pall - function that prints everything in the stack
* @top: double top pointer to the stack
* @counter: unused line count
*
* Return: nothing
*/
void _pall(stack_t **top, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *top;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* _swap - function that swaps the top two elements of the stack
* @top: top of stack
* @counter: line count
*
* Return: nothing
*/
void _swap(stack_t **top, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *top;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
