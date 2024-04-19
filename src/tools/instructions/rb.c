/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:18:32 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[B] == END_OF_STACK || stack->head[B] == stack->tail[B])
		return (1);
	tmp = stack->val[stack->head[B]].next;
	stack->val[stack->tail[B]].next = stack->head[B];
	stack->val[stack->head[B]].prev = stack->tail[B];
	stack->val[stack->head[B]].next = END_OF_STACK;
	stack->tail[B] = stack->head[B];
	stack->head[B] = tmp;
	stack->val[stack->head[B]].prev = END_OF_STACK;
	return (0);
}
