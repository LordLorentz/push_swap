/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:36:53 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	empty_stack(t_stack *stack, t_mode mode)
{
	stack->head[mode] = END_OF_STACK;
	stack->tail[mode] = END_OF_STACK;
}

int	pa(t_stack *stack)
{
	t_uint	tmp;

	if (stack->count[B] == 0)
		return (1);
	if (stack->count[A] == 0)
		stack->tail[A] = stack->head[B];
	else
		stack->val[stack->head[A]].prev = stack->head[B];
	tmp = stack->val[stack->head[B]].next;
	stack->val[stack->head[B]].prev = stack->tail[A];
	stack->val[stack->head[B]].next = stack->head[A];
	stack->val[stack->tail[A]].next = stack->head[B];
	stack->head[A] = stack->head[B];
	stack->head[B] = tmp;
	if (stack->count[B] > 1)
	{
		stack->val[stack->head[B]].prev = stack->tail[B];
		stack->val[stack->tail[B]].next = stack->head[B];
	}
	else
		empty_stack(stack, B);
	stack->count[A]++;
	stack->count[B]--;
	stack->val[stack->head[A]].container = A;
	return (0);
}
