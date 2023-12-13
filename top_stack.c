#include "monty.h"

/**
* _pstr - function that prints the string starting at the top of the stack,
* followed by a new
* @top: top of stack
* @line_num: line count
*
* Return: nothing
*/
void _pstr(stack_t **top, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *top;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
