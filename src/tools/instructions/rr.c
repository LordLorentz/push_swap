/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rr.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:24:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 16:49:57 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *stack)
{
	if (ra(stack))
		return (1);
	if (rb(stack))
		return (rra(stack), 1);
	return (0);
}
