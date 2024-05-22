/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   panel.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 19:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:34:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_proposal	init_proposal(t_uint panel_size)
{
	t_proposal	out;
	t_uint		i;

	out.dsc = DSC_EMPTY;
	out.parent = ORPHAN;
	i = 0;
	while (i < panel_size)
	{
		out.dpp[i] = EMPTY_DISAPPROVAL;
		i++;
	}
	return (out);
}

void	init_panel(t_proposal panel[], t_uint panel_size)
{
	t_uint	i;

	i = 0;
	while (i < panel_size)
	{
		panel[i] = init_proposal(panel_size);
		i++;
	}
}
