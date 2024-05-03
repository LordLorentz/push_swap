/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 14:35:36 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	t_uint	tmp;

	if (stack->count[A] < 3)
		return (1);
	tmp = stack->val[stack->head[A]].next;
	stack->val[stack->val[tmp].next].prev = stack->head[A];
	stack->val[stack->tail[A]].next = tmp;
	stack->val[stack->head[A]].prev = tmp;
	stack->val[stack->head[A]].next = stack->val[tmp].next;
	stack->val[tmp].prev = stack->tail[A];
	stack->val[tmp].next = stack->head[A];
	stack->head[A] = tmp;
	return (0);
}

// tmp = second (prev = tail next = head head = tmp)
// head (prev = tmp (second) next = tmp.next (third))
// tail (next = tmp (second))
// third (prev = head)
