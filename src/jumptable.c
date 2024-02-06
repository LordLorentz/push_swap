/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jumptable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:45:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/05 21:40:24 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Jumptable for push_swap instructions
// f() ^ 0xF = `f()  
static const t_inst	g_jumptable[16]
	= {
	NULL, &pa, &sa, &sb,
	&ss, &ra, &rb, &rr,
	&rrr, &rrb, &rra, &ss,
	&sb, &sa, &pb, NULL
};

//Algorithm specifications:
//--Takes two stacks and two discriminants
//--Performs the operations necessary to have the stacks represent discriminant
//		`next`, assuming they were entered representing discriminant `prev`
//--If `prev` is 0, simply executes all instructions in `next`
//--Any values before the beginning of the discriminant are assumed to be 
//		the same in both `prev` and `next`, and either 0xF or 0x0.
//--(sizeof(t_ulong) * 8) % DSC_SIZE should evaluate to 0.
//Returns 1 if the discriminant was invalid. Leaves the stacks representing
//		`prev`, in this case. X

void	scuttle_dsc(t_stack *a, t_stack *b, t_ulong prev, t_ulong next)
{
	int		shift;
	int		i;
	t_inst	current;

	shift = sizeof(t_ulong) * 8 - DSC_SIZE;
	while ((prev >> shift & DSC_LAST) == (next >> shift & DSC_LAST) && shift)
		shift -= DSC_SIZE;
	i = shift / DSC_SIZE;
	while (i-- >= 0)
	{
		current = g_jumptable[(prev & DSC_LAST) ^ 0xF];
		if (current != NULL)
			current(a, b);
		prev >>= DSC_SIZE;
	}
	while (shift >= 0)
	{
		current = g_jumptable[(next >> shift) & DSC_LAST];
		if (current != NULL)
			current(a, b);
		shift -= 4;
	}
}
