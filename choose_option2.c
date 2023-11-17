#include "monty.h"

/**
 * m_sub - Function that subtracts the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n -= tmp->n;
	m_pop(stack, line_number);
}

/**
 * m_div - Function that divide the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (!(tmp->n))
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}

	tmp->prev->n /= tmp->n;
	m_pop(stack, line_number);
}

/**
 * m_mul - Function that multiplies multiplies the second top element
 * of the stack with the top element of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}

	tmp->prev->n *= tmp->n;
	m_pop(stack, line_number);
}


/**
 * m_mod - Function that computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (!(tmp->n))
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}

	tmp->prev->n %= tmp->n;
	m_pop(stack, line_number);
}
/**
 * m_pchar - prints the char at the top of the stack + '\n'
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	for (; tmp->next; tmp = tmp->next)
		;
	if (tmp->n < 0 || tmp->n > 126)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
				line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
