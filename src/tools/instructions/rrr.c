/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:24:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:27:22 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_stack *a, t_stack *b)
{
	if (rra(a, b))
		return (1);
	if (rrb(a, b))
		return (ra(a, b), 1);
	return (0);
}
