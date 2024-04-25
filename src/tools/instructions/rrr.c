/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:24:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 16:49:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_stack *stack)
{
	if (rra(stack))
		return (1);
	if (rrb(stack))
		return (ra(stack), 1);
	return (0);
}
