#include "monty.h"

/**
* f_pstr - function that prints the string starting at the top of the stack,
* followed by a new
* @top: top of stack
* @counter: line count
*
* Return: nothing
*/
void f_pstr(stack_t **top, unsigned int counter)
{
	stack_t *h;
	(void)counter;

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
