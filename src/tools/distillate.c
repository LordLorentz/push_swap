/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distillate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 12:04:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/26 22:43:34 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Algorithms:
//--RA can only be followed by RRB if A has not yet been rotated in the current
//		associative plane.
//--__Same for the inverse operations.
//--SA requires an operation that modifies stack A before it can be repeated.

#include "push_swap.h"

static inline int	is_associative(t_inum inum)
{
	if (inum == _RA || inum == _RB || inum == _RR
			|| inum == RRR || inum == RRB || inum == RRA)
		return (1);
	else
		return (0);
}

t_dsc	cull_associative(t_dsc dsc)
{
	t_uint			i;
	unsigned char	current;

	i = 0;
	current = dsc >> (i * DSC_SIZE) & DSC_LAST;
	while (current != NON)
	{
		if (current == _RA || current == RRA)
		{

		}
		i++;
		current = dsc >> (i * DSC_SIZE) & DSC_LAST;
	}
	return (dsc);
}
