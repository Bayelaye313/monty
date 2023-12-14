#include "monty.h"

/**
 * _add - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _sub - function that subtracts nodes
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _sub(stack_t **top, __attribute__((unused))unsigned int linenum)
{
	stack_t *temp = *top;
	int sub = temp->next->n - temp->n;

	temp->next->n = sub;
	*top = temp->next;
	free(temp);
}

/**
 * _mul - function that multiplies the top two elements of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _mul(stack_t **top, __attribute__((unused))unsigned int linenum)
{
	stack_t *h = *top;
	int temp = h->next->n * h->n;

	h->next->n = temp;
	*top = h->next;
	free(h);
}

/**
 * _div - function that divides the top two elements of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _div(stack_t **top, unsigned int linenum)
{
	stack_t *h = *top;
	int temp;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
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
 * _mod - function that computes the remainder of the division
 * of the second top element of the stack by the top element of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _mod(stack_t **top, unsigned int linenum)
{
	stack_t *h = *top;
	int temp;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
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
