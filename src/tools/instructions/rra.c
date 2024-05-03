/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 15:02:56 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack)
{
	if (stack->count[A] < 2)
		return (1);
	stack->head[A] = stack->tail[A];
	stack->tail[A] = stack->val[stack->tail[A]].prev;
	return (0);
}
