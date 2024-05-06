/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   council_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:02:57 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/06 14:46:15 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inspect(t_branch **hedge, t_proposal panel[], t_dsc next)
{
	t_uint		i;
	t_branch	*branch;
	t_proposal	proposal;

	i = 0;
	while (i < PANEL_SIZE)
	{
		branch = hedge[i];
		if (scuttle_dsc(branch->stack, branch->current, next))
		{
			i++;
			continue ;
		}
		else
			branch->current = next;
		proposal = inquisit(branch->stack);
		proposal.dsc = branch->current;
		proposal.parent = branch->location;
		// print_proposal(proposal, "__-");
		insert_proposal(panel, proposal);
		i++;
	}
}

//Sets panel[] to the proper set of proposals for the next cycle.
void	discuss(t_branch **hedge, t_proposal panel[])
{
	t_uint	depth;
	t_dsc	next;

	init_panel(panel, PANEL_SIZE);
	inspect(hedge, panel, DSC_EMPTY);
	depth = 1;
	while (depth <= MAX_DEPTH)
	{
		next = mk_dsc(depth);
		while (next != DSC_END)
		{
			inspect(hedge, panel, next);
			next = iter_dsc(next);
		}
		depth++;
	}
	inspect(hedge, panel, DSC_EMPTY);
}

int	administrate(
		t_branch **hedge_root,
		t_branch **hedge_graft,
		t_proposal panel[])
{
	discuss(hedge_root, panel);
	while (is_sorted(panel) == false)
	{
		ft_printf("Extending!\n");
		if (extend_hedge(hedge_graft, hedge_root, panel))
			return (1);
		ft_swap((void **)&hedge_root, (void **)&hedge_graft);
		print_stacks(hedge_root[0]->stack);
		print_stacks(hedge_root[1]->stack);
		print_stacks(hedge_root[2]->stack);
		discuss(hedge_root, panel);
	}
	if (print_dsclist(hedge_root[0]->dsclist) == -1)
		return (1);
	return (0);
}

int	convene(t_stack *stack)
{
	t_branch	**hedge_root;
	t_branch	**hedge_graft;
	t_proposal	panel[PANEL_SIZE];
	t_uint		out;

	hedge_root = make_hedge(stack, HEDGE_SIZE);
	if (hedge_root == NULL)
		return (1);
	hedge_graft = make_hedge(stack, HEDGE_SIZE);
	if (hedge_graft == NULL)
		return (free_hedge(hedge_root, HEDGE_SIZE), 1);
	init_panel(panel, PANEL_SIZE);
	out = administrate(hedge_root, hedge_graft, panel);
	free_hedge(hedge_root, HEDGE_SIZE);
	free_hedge(hedge_graft, HEDGE_SIZE);
	return (out);
}
