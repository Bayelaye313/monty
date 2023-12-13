#include "monty.h"

/**
* _pall - function that prints everything in the stack
* @top: double top pointer to the stack
* @line_num: unused line count
*
* Return: nothing
*/
void _pall(stack_t **top, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

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
* @line_num: line count
*
* Return: nothing
*/
void _swap(stack_t **top, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
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
