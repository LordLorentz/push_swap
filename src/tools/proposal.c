/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   proposal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 19:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/25 22:20:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_proposal	init_proposal(t_dsc dsc, t_ulong dpp, t_uint parent_branch)
{
	t_proposal	out;

	out.dsc = dsc;
	out.dpp = dpp;
	out.parent_branch = parent_branch;
	return (out);
}

void	init_panel(t_proposal *panel, size_t panel_size)
{
	size_t	i;

	i = 0;
	while (i < panel_size)
	{
		panel[i] = init_proposal(DSC_EMPTY, EMPTY_DISAPPROVAL, 0);
		i++;
	}
}

int	insert_proposal(t_proposal *panel, size_t panel_size, t_proposal proposal)
{
	size_t	i;

	if (panel[panel_size - 1].dpp > proposal.dpp)
		return (0);
	i = 0;
	while (i < panel_size)
	{
		if (panel[i].dpp > proposal.dpp)
		{
			panel[i] = proposal;
			return (1);
		}
		i++;
	}
	return (-1);
}
