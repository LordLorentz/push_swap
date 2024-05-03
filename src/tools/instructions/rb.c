/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 13:12:59 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_stack *stack)
{
	if (stack->count[B] < 2)
		return (1);
	stack->tail[B] = stack->head[B];
	stack->head[B] = stack->val[stack->head[B]].next;
	return (0);
}
