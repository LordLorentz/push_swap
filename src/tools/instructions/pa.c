/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:30:16 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack)
{
	if (stack->head[B] == END_OF_STACK)
		return (1);
	if (stack->head[A] == END_OF_STACK)
		stack->tail[A] = stack->head[B];
	else
		stack->val[stack->head[A]].prev = stack->head[B];
	stack->val[stack->head[B]].prev = END_OF_STACK;
	stack->val[stack->head[B]].next = stack->head[A];
	stack->head[A] = stack->head[B];
	stack->head[B] = stack->val[stack->head[B]].next;
	if (stack->head[B] != END_OF_STACK)
		stack->val[stack->head[B]].prev = END_OF_STACK;
	stack->count[A]++;
	stack->count[B]--;
	stack->val[stack->head[A]].container = A;
	return (0);
}
