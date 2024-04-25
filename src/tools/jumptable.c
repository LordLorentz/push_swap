/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jumptable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:45:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 16:47:33 by mmosk         ########   odam.nl         */
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

static inline void	apply_dsc(t_stack *stack, t_dsc dsc, int shift)
{
	t_inst	current;

	while (shift >= 0)
	{
		current = g_jumptable[(dsc >> shift) & DSC_LAST];
		if (current != NULL)
			current(stack);
		shift -= 4;
	}
}

static inline void	revert_dsc(t_stack *stack, t_dsc dsc, int i)
{
	t_inst	current;

	while (i-- > 0)
	{
		current = g_jumptable[(dsc & DSC_LAST) ^ 0xF];
		if (current != NULL)
			current(stack);
		dsc >>= DSC_SIZE;
	}
}

static inline int	advance_dsc(t_stack *stack, t_dsc dsc, int shift)
{
	t_inst	current;
	int		i;

	i = 0;
	while (shift >= 0)
	{
		current = g_jumptable[(dsc >> shift) & DSC_LAST];
		if (current != NULL)
			if (current(stack))
				return (revert_dsc(stack, dsc >> (shift + DSC_SIZE), i), 1);
		shift -= DSC_SIZE;
		i++;
	}
	return (0);
}

//Algorithm specifications:
//--Takes two stacks and two discriminants
//--Performs the operations necessary to have the stacks represent discriminant
//		`next`, assuming they were entered representing discriminant `prev`
//--If `prev` is 0, simply executes all instructions in `next`
//--Any values before the beginning of the discriminant are assumed to be 
//		the same in both `prev` and `next`, and either 0xF or 0x0.
//--(sizeof(t_ulong) * 8) % DSC_SIZE should evaluate to 0.
//Returns 1 if the discriminant was invalid. Leaves the stacks representing
//		`prev`, in this case.
int	scuttle_dsc(t_stack *stack, t_dsc prev, t_dsc next)
{
	int		shift;
	int		i;
	int		out;

	shift = sizeof(t_dsc) * 8 - DSC_SIZE;
	while ((prev >> shift & DSC_LAST) == (next >> shift & DSC_LAST) && shift)
		shift -= DSC_SIZE;
	i = shift / DSC_SIZE;
	revert_dsc(stack, prev, i + 1);
	out = advance_dsc(stack, next, shift);
	if (out)
		apply_dsc(stack, prev, shift);
	return (out);
}
