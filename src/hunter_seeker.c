/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hunter_seeker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 21:52:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/05 21:41:20 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Algorithm specifications:
//--Runs one hunter-seeker cycle.
//--Takes two stacks and a discriminant to start with.
//--_-Cycle depth is defined by the length of the starting discriminant.
//--Returns the discriminant with the lowest disapproval rating.
//--Leaves the stacks in the state representing the returned discriminant.

t_ulong	run_cycle(t_stack *a, t_stack *b, t_ulong start, t_uint size)
{
	t_ulong	current_dpp;
	t_ulong	best_dpp;
	t_ulong	prev_dsc;
	t_ulong	current_dsc;
	t_ulong	best_dsc;

	scuttle_dsc(a, b, 0, start);
	best_dpp = inquisit(a, b, size);
	best_dsc = start;
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (current_dsc != DSC_END)
	{
		ft_printf("--_-dsc: %p\n", prev_dsc);
		debug_stacks(a, b);
		scuttle_dsc(a, b, prev_dsc, current_dsc);
		current_dpp = inquisit(a, b, size);
		if (current_dpp < best_dpp)
		{
			best_dpp = current_dpp;
			best_dsc = current_dsc;
		}
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, current_dsc, best_dsc);
	return (best_dsc);
}
