/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/22 14:04:30 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[B] == END_OF_STACK)
		return (1);
	if (stack->head[A] == END_OF_STACK)
		stack->tail[A] = stack->head[B];
	else
		stack->val[stack->head[A]].prev = stack->head[B];
	tmp = stack->val[stack->head[B]].next;
	stack->val[stack->head[B]].prev = END_OF_STACK;
	stack->val[stack->head[B]].next = stack->head[A];
	stack->head[A] = stack->head[B];
	stack->head[B] = tmp;
	if (stack->head[B] != END_OF_STACK)
		stack->val[stack->head[B]].prev = END_OF_STACK;
	stack->count[A]++;
	stack->count[B]--;
	stack->val[stack->head[A]].container = A;
	return (0);
}
