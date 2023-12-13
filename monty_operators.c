#include "monty.h"

/**
* _add - function that adds the top two elements of the stack
* @top: double pointer top to the stack
* @line_num: line count
*
* Return: nothing
*/
void _add(stack_t **top, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}

/**
* _sub - function that substracts nodes
* @top: double top pointer to the stack
* @line_num: line count
*
* Return: nothing
*/
void _sub(stack_t **top, unsigned int line_num)
{
	stack_t *temp;
	int sub, nd;

	temp = *top;
	for (nd = 0; temp != NULL; nd++)
		temp = temp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*top = temp->next;
	free(temp);
}

/**
* _mul - function that multiplies the top two elements of the stack
* @top: double top pointer to the stack
* @line_num: line count
*
* Return: nothing
*/
void _mul(stack_t **top, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}

/**
* _div - function that divides the top two elements of the stack
* @top: double top pointer to the stack
* @line_num: line count
*
* Return: nothing
*/
void _div(stack_t **top, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}

/**
* _mod - function that computes the remainder of the division of the second
* top element of the stack by the top element of the stack
* @top: double top pointer to the stack
* @line_num: line count
*
* Return: nothing
*/
void _mod(stack_t **top, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}
