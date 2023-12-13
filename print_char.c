#include "monty.h"

/**
* _pchar - function that prints the char at the top of the stack,
* followed by a new line
* @top: stack top
* @linenum: line count
*
* Return: nothing
*/
void _pchar(stack_t **top, unsigned int linenum)
{
	stack_t *h;

	h = *top;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", linenum);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", linenum);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
