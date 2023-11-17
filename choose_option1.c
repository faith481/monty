#include "monty.h"

/**
 * mega_pint - Add a new node at the end of a list
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void mega_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	for (; tmp->next; tmp = tmp->next)
		;
	printf("%d\n", tmp->n);

}

/**
 * m_pop - Function that removes the top element of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *tmp2 = NULL;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	for (; tmp && tmp->next; tmp = tmp->next)
		;
	tmp2 = tmp;
	tmp->prev->next = NULL;
	free(tmp2);
}

/**
 * m_swap - Function that swaps the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
	{
		(*stack)->prev = tmp;
		tmp->next = (*stack);
		(*stack)->next = NULL;
		*stack = tmp;
		(*stack)->prev = NULL;
		return;
	}
	tmp->prev = tmp->prev->prev;
	tmp->prev->next->next = NULL;
	tmp->next = tmp->prev->next;
	tmp->prev->next->prev = tmp;
	tmp->prev->next = tmp;
}

/**
 * m_add - Function that adds the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n += tmp->n;
	m_pop(stack, line_number);
}

/**
 * m_nop - Function that doesn't do anything
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
