/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specialists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:24:27 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/03 14:56:43 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

int	extend_hedge(t_branch **dst, t_branch **src, t_proposal panel[], t_uint size)
{
	t_uint	i;
	t_uint	src_branch;

	i = 0;
	while (i < PANEL_SIZE)
	{
		src_branch = panel[i].parent;
		copy_stack(dst[i]->a, src[src_branch]->a, size);
		copy_stack(dst[i]->b, src[src_branch]->b, size);
		if (overwrite_dsclist(dst[i]->dsclist, src[src_branch]->dsclist));
			return (1);
		scuttle_dsc(dst[i]->a, dst[i]->b, DSC_EMPTY, panel[i].dsc);
		if (append_dsclist(dst[i]->dsclist, panel[i].dsc))
			return (1);
		i++;
	}
	return (0);
}

bool	is_sorted(t_proposal panel[])
{
	t_uint i;

	i = 0;
	while (i < PANEL_SIZE)
	{
		if (panel[i].dsc == DSC_EMPTY && panel[i].dpp[0] == SORTED_DISAPPROVAL)
			return (true);
	}
	return (false);
}
