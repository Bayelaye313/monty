#include "monty.h"

/**
* f_add - function that adds the top two elements of the stack
* @top: double pointer top to the stack
* @counter: line count
*
* Return: nothing
*/
void f_add(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
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
* f_sub - function that substracts nodes
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_sub(stack_t **top, unsigned int counter)
{
	stack_t *temp;
	int sub, nd;

	temp = *top;
	for (nd = 0; temp != NULL; nd++)
		temp = temp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
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
* f_mul - function that multiplies the top two elements of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_mul(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
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
* f_div - function that divides the top two elements of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_div(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}

/**
* f_mod - function that computes the remainder of the division of the second
* top element of the stack by the top element of the stack
* @top: double top pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_mod(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*top = h->next;
	free(h);
}
