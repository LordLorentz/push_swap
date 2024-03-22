/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control_dsc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 13:50:28 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/22 17:58:46 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

//Discriminant specifications:
//--

//Variable base for the discriminant.
//For this grid:
//Y is the value of the previous digit in the discriminant.
//X is the current value of the current digit in the discriminant.
//Stored value is the next value of the current digit in the discriminant.
//NON should not appear, END means the digit has reached the end of its base
//and should increment the previous digit.
//I shan't be held accountable for any optometric costs you incur in trying to
//read it.
static const unsigned char	g_crazebase[16][16]
	= {
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{NON},
{NON},
{NON},
{_PA, _SA, _SB, _SS, _RA, _RB, _RR, RRR, RRB, RRA, _PB, NON, NON, NON, END},
{END}
};

static inline unsigned char	deref_crazebase(t_dsc dsc)
{
	return (g_crazebase[dsc >> DSC_SIZE & DSC_LAST][dsc & DSC_LAST]);
}

t_dsc	inc_dsc(t_dsc discriminant)
{
	unsigned char	current;

	current = deref_crazebase(discriminant);
	if (current == END)
	{
		if ((discriminant >> DSC_SIZE & DSC_LAST) == NON)
			return (DSC_END);
		discriminant = inc_dsc(discriminant >> DSC_SIZE) << DSC_SIZE;
		current = deref_crazebase(discriminant);
	}
	discriminant = (discriminant & DSC_BODY) | current;
	return (discriminant);
}
