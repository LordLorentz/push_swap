/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 16:21:55 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[B] == END_OF_STACK || stack->head[B] == stack->tail[B]
			|| stack->val[stack->head[B]].next == stack->tail[B])
		return (1);
	tmp = stack->val[stack->head[B]].next;
	stack->val[stack->val[tmp].next].prev = stack->head[B];
	stack->val[stack->head[B]].prev = tmp;
	stack->val[stack->head[B]].next = stack->val[tmp].next;
	stack->val[tmp].prev = END_OF_STACK;
	stack->val[tmp].next = stack->head[B];
	stack->head[B] = tmp;
	return (0);
}
