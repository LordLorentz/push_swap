/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 16:22:35 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	t_uint	tmp;

	if (stack->head[A] == END_OF_STACK || stack->head[A] == stack->tail[A]
			|| stack->val[stack->head[A]].next == stack->tail[A])
		return (1);
	tmp = stack->val[stack->head[A]].next;
	stack->val[stack->val[tmp].next].prev = stack->head[A];
	stack->val[stack->head[A]].prev = tmp;
	stack->val[stack->head[A]].next = stack->val[tmp].next;
	stack->val[tmp].prev = END_OF_STACK;
	stack->val[tmp].next = stack->head[A];
	stack->head[A] = tmp;
	return (0);
}
