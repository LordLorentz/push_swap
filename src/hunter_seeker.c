/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hunter_seeker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 21:52:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/07 14:31:38 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Algorithm specifications:
//--Runs one hunter-seeker cycle.
//--Takes two stacks and a discriminant to start with.
//--_-Cycle depth is defined by the length of the starting discriminant.
//--Returns the discriminant with the lowest disapproval rating.
//--Leaves the stacks in the state representing the returned discriminant.

static inline void	assign_best(t_ulong *_a, t_ulong *_b, t_ulong a, t_ulong b)
{
	*_a = a;
	*_b = b;
}

t_ulong	run_cycle(t_stack *a, t_stack *b, t_ulong start, t_uint size)
{
	t_ulong	current_dpp;
	t_ulong	best_dpp;
	t_ulong	prev_dsc;
	t_ulong	current_dsc;
	t_ulong	best_dsc;

	while (scuttle_dsc(a, b, 0, start))
		start = iter_dsc(start);
	best_dpp = inquisit(a, b, size);
	best_dsc = start;
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		while (scuttle_dsc(a, b, prev_dsc, current_dsc))
			current_dsc = iter_dsc(current_dsc);
		current_dpp = inquisit(a, b, size);
		if (current_dpp < best_dpp)
			assign_best(&best_dpp, &best_dsc, current_dpp, current_dsc);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, prev_dsc, best_dsc);
	return (best_dsc);
}
