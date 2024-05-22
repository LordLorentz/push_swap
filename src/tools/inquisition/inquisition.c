/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inquisition.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 20:04:07 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:38:34 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Multi-step heuristics??!
//Multi-cellular heuristics.
//Both.

t_proposal	inquisit(t_stack *stack, t_lense lense)
{
	t_proposal	out;
	t_uint		i;

	i = 0;
	while (i < PANEL_SIZE)
	{
		out.dpp[i] = technoblade(stack, lense.bias[i], lense.focus[i]);
		i++;
	}
	return (out);
}
