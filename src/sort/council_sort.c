/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   council_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:02:57 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 12:49:38 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inspect(t_branch **hedge, t_proposal panel[], t_dsc next, t_uint size)
{
	t_uint		i;
	t_branch	*branch;
	t_proposal	proposal;

	i = 0;
	while (i < PANEL_SIZE)
	{
		branch = hedge[i];
		if (scuttle_dsc(branch->a, branch->b, branch->current, next))
		{
			i++;
			continue ;
		}
		else
			branch->current = next;
		proposal = inquisit(branch->a, branch->b, size);
		proposal.dsc = branch->current;
		proposal.parent = branch->location;
		// print_proposal(proposal, "__-");
		insert_proposal(panel, proposal);
		i++;
	}
}

//Sets panel[] to the proper set of proposals for the next cycle.
void	discuss(t_branch **hedge, t_proposal panel[], t_uint size)
{
	t_uint	depth;
	t_dsc	next;

	init_panel(panel, PANEL_SIZE);
	inspect(hedge, panel, DSC_EMPTY, size);
	depth = 1;
	while (depth <= MAX_DEPTH)
	{
		next = mk_dsc(depth);
		while (next != DSC_END)
		{
			inspect(hedge, panel, next, size);
			next = iter_dsc(next);
		}
		depth++;
	}
	inspect(hedge, panel, DSC_EMPTY, size);
}

int	administrate(
		t_branch **hedge_root,
		t_branch **hedge_graft,
		t_proposal panel[],
		t_uint size)
{
	discuss(hedge_root, panel, size);
	while (is_sorted(panel) == false)
	{
		ft_printf("Extending!\n");
		if (extend_hedge(hedge_root, hedge_graft, panel, size))
			return (1);
		ft_swap((void **)&hedge_root, (void **)&hedge_graft);
		print_stacks(hedge_root[0]->a, hedge_root[0]->b);
		print_stacks(hedge_root[1]->a, hedge_root[1]->b);
		print_stacks(hedge_root[2]->a, hedge_root[2]->b);
		discuss(hedge_root, panel, size);
	}
	if (print_dsclist(hedge_root[0]->dsclist) == -1)
		return (1);
	return (0);
}

int	convene(t_stack *a, t_stack *b, t_uint size)
{
	t_branch	**hedge_root;
	t_branch	**hedge_graft;
	t_proposal	panel[PANEL_SIZE];
	t_uint		out;

	hedge_root = make_hedge(a, b, HEDGE_SIZE, size);
	if (hedge_root == NULL)
		return (1);
	hedge_graft = make_hedge(a, b, HEDGE_SIZE, size);
	if (hedge_graft == NULL)
		return (free_hedge(hedge_root, HEDGE_SIZE), 1);
	init_panel(panel, PANEL_SIZE);
	out = administrate(hedge_root, hedge_graft, panel, size);
	free_hedge(hedge_root, HEDGE_SIZE);
	free_hedge(hedge_graft, HEDGE_SIZE);
	return (out);
}
