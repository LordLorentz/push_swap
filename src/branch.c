/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   branch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/14 13:05:51 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/15 18:10:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_branch	*make_branch(t_stack *a, t_stack *b, t_uint location, t_uint size)
{
	t_branch	*out;

	out = malloc(sizeof(t_branch));
	if (out == NULL)
		return (NULL);
	out->a = clone_stack(size, a);
	if (out->a == NULL)
		return (free(out), NULL);
	out->b = clone_stack(size, b);
	if (out->b == NULL)
		return (free(out->a), free(out), NULL);
	out->dsclist = NULL;
	out->location = location;
	return (out);
}
//gnarly memory conflicts
void	free_branch(t_branch *branch)
{
	free_stack(branch->a);
	free_stack(branch->b);
	free_dsclist(branch->dsclist);
	free(branch);
}

t_branch	**make_hedge(t_stack *a, t_stack *b, t_uint hedge_size, t_uint size)
{
	t_branch	**hedge;
	t_uint		i;

	hedge = malloc(sizeof(t_branch *) * hedge_size);
	if (hedge == NULL)
		return (NULL);
	i = 0;
	while (i < hedge_size)
	{
		hedge[i] = make_branch(a, b, i, size);
		if (hedge[i] == NULL)
			return (free_hedge(hedge, i), NULL);
		i++;
	}
	return (hedge);
}

void	free_hedge(t_branch **hedge, t_uint hedge_size)
{
	t_uint	i;

	i = 0;
	while (i < hedge_size)
	{
		free_branch(hedge[i]);
		i++;
	}
	free(hedge);
}

int	extend_branch(t_branch *dst, t_branch *src, t_proposal proposal, t_uint sz)
{
	
}

int	extend_hedge(t_branch **dst, t_branch **src, t_proposal *panel, t_twoint sz)
{
	t_uint	i;
	t_uint	src_branch;

	i = 0;
	while (i < sz.panel)
	{
		src_branch = panel[i].parent_branch;
		copy_stack(dst[i]->a, src[src_branch]->a, sz.stack);
		copy_stack(dst[i]->b, src[src_branch]->b, sz.stack);
		if (overwrite_dsclist(dst[i]->dsclist, src[src_branch]->dsclist));
			return (1);
		scuttle_dsc(dst[i]->a, dst[i]->b, DSC_EMPTY, panel[i].dsc);
		if (append_dsclist(dst[i]->dsclist, panel[i].dsc))
			return (1);
		i++;
	}
	return (0);
}//find cleaner fix for variable limit
