/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 14:51:24 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrb(t_stack *stack)
{
	if (stack->count[B] < 2)
		return (1);
	stack->head[B] = stack->tail[B];
	stack->tail[B] = stack->val[stack->tail[B]].prev;
	return (0);
}
