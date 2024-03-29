/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   panel.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 19:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/29 15:20:57 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_panel(t_proposal panel[], t_uint panel_size)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (i < panel_size)
	{
		panel[i].dsc = DSC_EMPTY;
		panel[i].parent = ORPHAN;
		j = 0;
		while (j < panel_size)
		{
			panel[i].dpp[j] = EMPTY_DISAPPROVAL;
			j++;
		}
		i++;
	}
}

void	insert_proposal(t_proposal panel[], t_proposal proposal)
{
	t_uint	i;
	t_uint	j;
	t_uint	identity;

	i = 0;
	while (i < PANEL_SIZE)
	{
		j = 0;
		identity = 1;
		while (j < PANEL_SIZE)
		{
			identity += (panel[i].dpp[j] == proposal.dpp[j]);
			j++;
		}
		if (identity == PANEL_SIZE)
			return ;
		if (panel[i].dpp[i] > proposal.dpp[i])
		{
			panel[i] = proposal;
			return ;
		}
		i++;
	}
}//move this?
