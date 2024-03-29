/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   council_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:02:57 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/29 15:04:04 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extend_hedge(t_branch **dst, t_branch **src, t_proposal *panel, t_uint size)
{
	t_uint	i;
	t_uint	src_branch;

	i = 0;
	while (i < PANEL_SIZE)
	{
		src_branch = panel[i].parent_branch;
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

t_proposal	proliferate_branch(t_branch *branch, t_dsc prev, t_uint size)
{
	t_proposal	out;

	out.dsc = iter_dsc(prev);
	out.parent_branch = branch->location;
	
}

int	run_council(t_stack *a, t_stack *b, t_uint size)
{
	t_branch	**left_hedge;
	t_branch	**right_hedge;
	t_proposal	panel[PANEL_SIZE];

	left_hedge = make_hedge(a, b, HEDGE_SIZE, size);
	if (left_hedge == NULL)
		return (1);
	right_hedge = make_hedge(a, b, HEDGE_SIZE, size);
	if (right_hedge == NULL)
		return (free_hedge(left_hedge, HEDGE_SIZE), 1);

}
