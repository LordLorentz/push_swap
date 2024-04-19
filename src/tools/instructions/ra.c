/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:17:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[A] == END_OF_STACK || stack->head[A] == stack->tail[A])
		return (1);
	tmp = stack->val[stack->head[A]].next;
	stack->val[stack->tail[A]].next = stack->head[A];
	stack->val[stack->head[A]].prev = stack->tail[A];
	stack->val[stack->head[A]].next = END_OF_STACK;
	stack->tail[A] = stack->head[A];
	stack->head[A] = tmp;
	stack->val[stack->head[A]].prev = END_OF_STACK;
	return (0);
}
