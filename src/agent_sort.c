/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   agent_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 21:52:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/11 18:33:40 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Algorithm specifications:
//--Runs one hunter-seeker cycle.
//--Takes two stacks and a discriminant to start with.
//--_-Cycle depth is defined by the length of the starting discriminant.
//--Returns the discriminant with the lowest disapproval rating.
//--Leaves the stacks in the state representing the returned discriminant.

t_stackstate	run_cycle(t_stack *a, t_stack *b, t_ulong start, t_uint size)
{
	t_stackstate	current;
	t_stackstate	best;
	t_ulong			prev_dsc;

	while (scuttle_dsc(a, b, DSC_EMPTY, start))
		start = iter_dsc(start);
	best.dpp = inquisit(a, b, size);
	best.dsc = start;
	prev_dsc = start;
	current.dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current.dsc != DSC_END, 1))
	{
		while (scuttle_dsc(a, b, prev_dsc, current.dsc))
			current.dsc = iter_dsc(current.dsc);
		current.dpp = inquisit(a, b, size);
		if (current.dpp < best.dpp)
			best = current;
		prev_dsc = current.dsc;
		current.dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, prev_dsc, best.dsc);
	return (best);
}

t_stackstate	rifle_cycle(t_stack *a, t_stack *b, t_uint depth, t_uint size)
{
	t_stackstate	current;
	t_stackstate	best;
	t_uint			i;

	best.dsc = 0;
	best.dpp = inquisit(a, b, size);
	i = 0;
	while (i < depth)
	{
		current = run_cycle(a, b, mk_dsc(i), size);
		scuttle_dsc(a, b, current.dsc, DSC_EMPTY);
		if (current.dpp < best.dpp)
			best = current;
		i++;
	}
	scuttle_dsc(a, b, DSC_EMPTY, best.dsc);
	return (best);
}

//Named Gossman, after both the stupidest and most intelligent clone I've ever
//		had the privilege to command.
//O(n) = n^2.5
void	agent_sort(t_stack *a, t_stack *b, t_uint size, t_uint depth)
{
	t_stackstate	current;
	t_stackstate	prev;

	current.dpp = inquisit(a, b, size);
	ft_printf("DPP: %p\n", current.dpp);
	print_stacks(a, b);
	prev.dpp = EMPTY_DISAPPROVAL;
	t_uint	total = 0;
	while (current.dpp != 0)
	{
		if (current.dpp < RIFLE_START)
			current = rifle_cycle(a, b, depth, size);
		else
			current = run_cycle(a, b, mk_dsc(depth), size);
		if (current.dpp == prev.dpp)
		{
			exit_wrapper();
			scuttle_dsc(a, b, current.dsc, JOLT);
			current.dsc = JOLT;
			current.dpp = inquisit(a, b, size);
			total += 16;
			ft_printf("JOLT\n");
		}
		else
			total += MAX_DEPTH;
		// print_dsc(current.dsc);
		prev = current;
		ft_printf("DPP: %p\nDSC: %p\n", current.dpp, current.dsc);
		print_stacks(a, b);
	}
	ft_printf("TOTAL: %u\n", total);
}
