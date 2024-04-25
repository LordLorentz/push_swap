/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specialists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:24:27 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 17:12:48 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Identity test is deterministic, as even though it loops through the panel
//	parallel to the insertion check, any proposal near the end of the panel
//	that may cause the identity test to fail will be reached, because if that
//	proposal could have been inserted sooner, it would have been, and in the
//	case of a failed identity test the proposal being evaluated is identical
//	to it.

void	insert_proposal(t_proposal panel[], t_proposal proposal)
{
	t_uint	i;
	t_uint	j;
	t_uint	identity;

	i = 0;
	while (i < PANEL_SIZE)
	{
		j = 0;
		identity = 0;
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

int	extend_hedge(
		t_branch **dst,
		t_branch **src,
		t_proposal panel[],
		t_uint size)
{
	t_uint	i;
	t_uint	src_branch;

	i = 0;
	while (i < PANEL_SIZE)
	{
		src_branch = panel[i].parent;
		if (src_branch == ORPHAN)
			src_branch = 0;
		copy_stack(dst[i]->stack, src[src_branch]->stack, size);
		if (overwrite_dsclist(&dst[i]->dsclist, src[src_branch]->dsclist))
			return (ft_printf("OVERWRITE\n"), 1);
		scuttle_dsc(dst[i]->stack, DSC_EMPTY, panel[i].dsc);
		if (append_dsclist(&dst[i]->dsclist, panel[i].dsc))
			return (ft_printf("APPEND\n"), 1);
		i++;
	}
	return (0);
}

//Only checks agent #1.
bool	is_sorted(t_proposal panel[])
{
	t_uint i;

	i = 0;
	while (i < PANEL_SIZE)
	{
		print_proposal(panel[i], "");
		i++;
	}
	i = 0;
	while (i < PANEL_SIZE)
	{
		if (panel[i].dsc == DSC_EMPTY && panel[i].dpp[0] == SORTED_DISAPPROVAL)
			return (true);
		i++;
	}
	return (false);
}
