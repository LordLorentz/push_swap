/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 15:04:58 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack->head[B] = stack->head[A];
	stack->head[A] = tmp;
	if (stack->count[A] > 1)
	{
		stack->val[stack->head[A]].prev = stack->tail[A];
		stack->val[stack->tail[A]].next = stack->head[A];
	}
	else
	{
		stack->head[A] = END_OF_STACK;
		stack->tail[A] = END_OF_STACK;
	}
	stack->count[B]++;
	stack->count[A]--;
	stack->val[stack->head[B]].container = B;
	return (0);
}
