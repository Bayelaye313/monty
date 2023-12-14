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
/**
* _pall - function that prints everything in the stack
* @top: double top pointer to the stack
* @linenum: unused line count
*
* Return: nothing
*/

void _pall(stack_t **top, __attribute__ ((unused)) unsigned int linenum)
{
	stack_t *run;

	run = *top;
	while (run != NULL)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}

/**
* _pint - function that prints the top of the stack
* @top: double top pointer to the stack
* @linenum: line count
*
* Return: nothing
*/
void _pint(stack_t **top, unsigned int linenum)
{
stack_t *run;

	run = *top;
	if (run == NULL)
	{
		printf("L%d: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", run->n);
}
/**
* _pstr - function that prints the string starting at the top of the stack,
* followed by a new
* @top: top of stack
* @linenum: line count
*
* Return: nothing
*/
void _pstr(stack_t **top, unsigned int linenum)
{
	stack_t *h;
	(void)linenum;

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

/**
* _nop - function that does nothing
* @top: double top pointer to the stack
* @linenum: line count
*
* Return: nothing
*/
void _nop(stack_t **top, unsigned int linenum)
{
	(void) top;
	(void) linenum;
}
