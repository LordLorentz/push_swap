/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distillate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 12:04:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:33:46 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Algorithms:
//--RA can only be followed by RRB if A has not yet been rotated in the current
//		associative plane.
//--__Same for the inverse operations.
//--SA requires an operation that modifies stack A before it can be repeated.

//I think this might be pointless.

static inline int	is_associative(t_inum inum)
{
	if (inum == _RA || inum == _RB || inum == _RR
		|| inum == RRR || inum == RRB || inum == RRA)
		return (1);
	else
		return (0);
}

t_dsc	cull_associative(t_dsc dsc, t_uint i, t_inum current)
{
	t_uint	j;
	t_inum	root;

	j = 1;
	root = dsc >> ((i + j) * DSC_SIZE) & DSC_LAST;
	while (is_associative(root))
	{
		root = dsc >> ((i + j) * DSC_SIZE) & DSC_LAST;
		j++;
	}
	j -= 2;
	root = dsc >> ((i + j) * DSC_SIZE) & DSC_LAST;
	if (root == RRR && current == _RA)
		dsc = (dsc & bit_not(0xF << (i * DSC_SIZE)))
			| (RRB << (i * DSC_SIZE));
	else if (root == _RR && current == RRA)
		dsc = (dsc & bit_not(0xF << (i * DSC_SIZE)))
			| (_PB << (i * DSC_SIZE));
	return (dsc);
}

t_dsc	distil(t_dsc dsc)
{
	t_uint	i;
	t_inum	current;

	i = 0;
	current = dsc >> (i * DSC_SIZE) & DSC_LAST;
	while (current != NON && current != END)
	{
		if (current == _RA || current == RRA)
			dsc = cull_associative(dsc, i, current);
		i++;
		current = dsc >> (i * DSC_SIZE) & DSC_LAST;
	}
	return (dsc);
}
