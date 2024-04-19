/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:26:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[A] == END_OF_STACK || stack->head[A] == stack->tail[A])
		return (1);
	tmp = stack->val[stack->tail[A]].prev;
	stack->val[stack->head[A]].prev = stack->tail[A];
	stack->val[stack->tail[A]].prev = END_OF_STACK;
	stack->val[stack->tail[A]].next = stack->head[A];
	stack->head[A] = stack->tail[A];
	stack->tail[A] = tmp;
	stack->val[stack->tail[A]].next = END_OF_STACK;
	return (0);
}
