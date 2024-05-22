/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:37:14 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	empty_stack(t_stack *stack, t_mode mode)
{
	stack->head[mode] = END_OF_STACK;
	stack->tail[mode] = END_OF_STACK;
}

int	pb(t_stack *stack)
{
	t_uint	tmp;

	if (stack->count[A] == 0)
		return (1);
	if (stack->count[B] == 0)
		stack->tail[B] = stack->head[A];
	else
		stack->val[stack->head[B]].prev = stack->head[A];
	tmp = stack->val[stack->head[A]].next;
	stack->val[stack->head[A]].prev = stack->tail[B];
	stack->val[stack->head[A]].next = stack->head[B];
	stack->val[stack->tail[B]].next = stack->head[A];
	stack->head[B] = stack->head[A];
	stack->head[A] = tmp;
	if (stack->count[A] > 1)
	{
		stack->val[stack->head[A]].prev = stack->tail[A];
		stack->val[stack->tail[A]].next = stack->head[A];
	}
	else
		empty_stack(stack, A);
	stack->count[B]++;
	stack->count[A]--;
	stack->val[stack->head[B]].container = B;
	return (0);
}
