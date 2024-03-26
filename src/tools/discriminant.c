/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   discriminant.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 13:50:28 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/26 22:35:15 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Variable base for the discriminant.
//For this grid:
//Y is the value of the previous digit in the discriminant.
//X is the current value of the current digit in the discriminant.
//Stored value is the next value of the current digit in the discriminant.
//NON should not appear, END means the digit has reached the end of its base
//and should increment the previous digit.
//I shan't be held accountable for any optometric costs you incur in trying to
//read it.
static const t_inum	g_crazebase[16][16]
	= {
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, END},
{_PA, _RA, NON, NON, NON, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _RA, NON, NON, NON, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _RA, NON, NON, NON, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SS, NON, _RA, _PB, NON, NON, NON, NON, NON, NON, NON, NON, END},
{_PA, _SB, NON, _SS, _RB, NON, RRA, NON, NON, NON, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, _PB, NON, NON, NON, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, RRR, NON, NON, NON, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SB, NON, _SS, _RA, RRB, NON, NON, NON, _PB, NON, NON, NON, NON, END},
{_PA, _SA, _SS, NON, RRA, NON, NON, NON, NON, NON, _PB, NON, NON, NON, END},
{NON},
{NON},
{NON},
{_SA, NON, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{END}
};

//!!!THIS VERSION LOSES ONE UNIQUE SOLUTION AT 3 ITERATIONS!!!
//No it doesn't. Obscure bug in my evaluation, didn't consider starting pos.

//You made it through!
//You may now laugh, scream, or turn into a murder of crows and peck my eyes out

static inline t_inum	deref_crazebase(t_dsc dsc)
{
	return (g_crazebase[dsc >> DSC_SIZE & DSC_LAST][dsc & DSC_LAST]);
}

//ft_printf("__-Current: %X\n--_Cut: %X\n", (unsigned long)current, 
//(discriminant & DSC_BODY));

static t_dsc	recurse_dsc(t_dsc discriminant)
{
	t_inum	current;

	current = deref_crazebase(discriminant);
	if (current == END)
	{
		if ((discriminant >> DSC_SIZE & DSC_LAST) == NON)
			return (DSC_END);
		discriminant = recurse_dsc(discriminant >> DSC_SIZE) << DSC_SIZE;
		current = deref_crazebase(discriminant);
	}
	discriminant = (discriminant & DSC_BODY) | current;
	return (discriminant);
}

//Iter_dsc specifications:
//--Takes any discriminant (moveset).
//--Returns the next valid discriminant.
//--__Should be able to find ALL movesets with a unique effect on the stacks.
//		Example: `ra pb` and `pb ra` have unique effects.
//--__Should find as few movesets with duplicate effects as possible.
//		Example: `ra rrb` and `rrb ra` have duplicate effects.
t_dsc	iter_dsc(t_dsc discriminant)
{
	t_dsc	out;

	out = recurse_dsc(discriminant);
	return (out);
}

t_dsc	mk_dsc(t_uint depth)
{
	t_dsc	out;

	out = 0;
	while (depth--)
	{
		out <<= DSC_SIZE;
		out |= _PA;
	}
	return (out);
}
