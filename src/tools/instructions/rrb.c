/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:27:07 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrb(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[B] == END_OF_STACK || stack->head[B] == stack->tail[B])
		return (1);
	tmp = stack->val[stack->tail[B]].prev;
	stack->val[stack->head[B]].prev = stack->tail[B];
	stack->val[stack->tail[B]].prev = END_OF_STACK;
	stack->val[stack->tail[B]].next = stack->head[B];
	stack->head[B] = stack->tail[B];
	stack->tail[B] = tmp;
	stack->val[stack->tail[B]].next = END_OF_STACK;
	return (0);
}
